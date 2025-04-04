#pragma once

/*
    void CreateRequest() must be overridden by extending Requester class
    to make a concrete object. Otherwise it is abstract !
*/

#include <string>
#include <boost/asio.hpp>
#include "irequester.hpp"

constexpr const char* PORT = "80";

class Requester : public IRequester{
protected:
    std::string json_string_;
    std::string request_;
    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::socket socket_;
    boost::asio::streambuf response_;
    boost::system::error_code error_;
    
    void Request() override;
    void CreateConnection();
    void SendRequest();
    virtual void ProcessResponse() override;

public:
    Requester();
    virtual ~Requester() = default;
    const std::string& GetResponse() const override;
};
