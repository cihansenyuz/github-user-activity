#include "../inc/requester.hpp"
#include <fstream>
#include <iostream>

Requester::Requester(const std::string& server)
    : server_{server}, socket_{io_context_, ssl_context_}, response_{} {

    ssl_context_.set_default_verify_paths();
}

void Requester::CreateConnection() {
    boost::asio::ip::tcp::resolver resolver(io_context_);
    // std::cout << "[Requester][CreateConnection]server: " << server_ << std::endl;
    auto endpoints = resolver.resolve(server_, PORT);
    boost::asio::connect(socket_.lowest_layer(), endpoints);
    socket_.handshake(boost::asio::ssl::stream_base::client);
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
    std::size_t bytes_transferred = read_until(socket_, response_, "\r\n\r\n", error_);
    
    if (bytes_transferred == 0) {
        std::cerr << "Error: No data received from the server.\n";
        return;
    }

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
    
    while (std::getline(response_stream, header)
            && header != "\r") {} // skip headers
    /* 
        headers and the body is seperated by \r\n in an http reply
        since getline reads until the \n, line ends with \r
        is the final line of the header
    */

    // Read the body and skip until the first '['
    json_string_.clear();
    char c;
    while (response_stream.get(c)) {
        if (c == '[') {
            json_string_ += c; // Add the '[' to the JSON string
            break;
        }
    }

    std::string line;

    while(read(socket_, response_, boost::asio::transfer_at_least(1), error_)) {
        std::istream response_stream(&response_);
        while (std::getline(response_stream, line)) {
            // std::cout << "[Requester][ProcessResponse] line: " << line << std::endl;
            json_string_ += line;
        }
    }

    // Skip remaining characters after the last ']'
    auto last_bracket_pos = json_string_.find_last_of(']');
    if (last_bracket_pos != std::string::npos) {
        json_string_ = json_string_.substr(0, last_bracket_pos + 1);
    }
    
    // if (error_ == error::eof)
    //     std::cout << "[Requester][ProcessResponse] Server closed the connection.\n";

    if(error_ != boost::asio::error::eof)
        throw boost::system::system_error{error_};
}