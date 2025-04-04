#pragma once

#include <string>
#include "requester.hpp"

class GitHubRequester : public Requester{
private:
    std::string username_;
    void CreateRequest() override;

public:
    GitHubRequester(const std::string& username);
    void MakeRequestToApi();
};