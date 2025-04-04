#pragma once

#include <string>
#include <boost/asio.hpp>
#include "irequester.hpp"

constexpr const char* PORT = "80";

class Requester : public IRequester{
protected:
    std::string json_string_;
    std::string server_, key_, request_;
    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::socket socket_;
    boost::asio::streambuf response_;
    boost::system::error_code error_;
    
    void Request() override;
    void CreateConnection();
    void SendRequest();
    virtual void ProcessResponse() override;

public:
    Requester(const std::string& server, const std::string& key);
    virtual ~Requester() = default;
    const std::string& GetResponse() const override;
};
