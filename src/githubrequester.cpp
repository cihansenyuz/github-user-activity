#include <iostream>
#include <boost/asio.hpp>
#include "../inc/githubrequester.hpp"

GitHubRequester::GitHubRequester(const std::string& username)
    : username_{username}, Requester{"api.github.com"} {}

void GitHubRequester::CreateRequest(){
    request_.clear();
    request_ += "GET /users/" + username_ + "/events HTTP/1.1\r\n";
    request_ += "Host: " + server_ + "\r\n";
    request_ += "User-Agent: github_user_activity_fetcher/0.1\r\n";
    request_ += "Connection: close\r\n\r\n";
}

void GitHubRequester::MakeRequestToApi() {
    Request();
}