#pragma once

#include "githubevent.hpp"
#include "githubrequester.hpp"
#include <memory>

class Application{
public:
    Application(const std::string &user_name);
    void PrintEventStats() const;

private:
    std::unique_ptr<GitHubRequester> gh_requester_;
    std::vector<GitHubEvent> events;
};