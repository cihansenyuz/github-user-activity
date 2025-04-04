#include <iostream>
#include <boost/asio.hpp>
#include "../inc/githubrequester.hpp"

GitHubRequester::GitHubRequester(const std::string& username)
    : username_{username}, Requester{SERVER} {}

void GitHubRequester::CreateRequest(){
    request_.clear();
    request_ += "GET https://api.github.com/users/" + username_ + "/events";
    request_ += "Host: " + server_ + "\r\n";
    request_ += "Connection: close\r\n\r\n";
}

void GitHubRequester::MakeRequestToApi() {
    Request();
}