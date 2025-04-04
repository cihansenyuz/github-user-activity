#pragma once

#include <string>
#include "requester.hpp"

class GitHubRequester : public Requester{
private:
    std::string username_;
    const std::string SERVER = "https://api.github.com/";
    void CreateRequest() override;

public:
    GitHubRequester(const std::string& username);
    void MakeRequestToApi();
};