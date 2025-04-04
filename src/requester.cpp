#include "../inc/requester.hpp"
#include <fstream>
#include <iostream>

Requester::Requester()
    : socket_{io_context_}, response_{} {
}

void Requester::CreateConnection() {
    boost::asio::ip::tcp::resolver resolver(io_context_);
    auto endpoints = resolver.resolve(server_, PORT);
    boost::asio::connect(socket_, endpoints);
}

void Requester::SendRequest(){
    boost::asio::write(socket_, boost::asio::buffer(request_));
    std::cout << "Request sent..." << std::endl;
}

void Requester::Request(){
    CreateConnection();
    CreateRequest();
    SendRequest();
    ProcessResponse();
}

const std::string& Requester::GetResponse() const{
    return json_string_;
}

void Requester::ProcessResponse(){
    read_until(socket_, response_, "\r\n\r\n");
    std::istream response_stream(&response_);

    std::string http_version;
    unsigned int status_code;
    std::string status_message;

    response_stream >> http_version >> status_code;
    std::getline(response_stream, status_message);

    if (status_code != 200) {
        std::cerr << "Error: Response returned with status code " << status_code << "\n";
        return;
    }

    std::string header;
    
    while (std::getline(response_stream, header) && header != "\r") {} // skip headers
    /* 
        headers and the body is seperated by \r\n in an http reply
        since getline reads until the \n, line ends with \r
        is the final line of the header
    */

    json_string_.clear();
    std::string line;

    while(read(socket_, response_, boost::asio::transfer_at_least(1), error_)) {
        std::istream response_stream(&response_);
        while (std::getline(response_stream, line)) {
            json_string_ += line;
        }
    }

    // if (error_ == error::eof)
    //     std::cout << "[Requester][ProcessResponse] Server closed the connection.\n";

    if(error_ != boost::asio::error::eof)
        throw boost::system::system_error{error_};
}