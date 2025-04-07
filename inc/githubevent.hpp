#pragma once

#include <string>

struct GitHubEvent{
    std::string type;
    std::string repo_name;
    std::string date;
    /*
    ... more fields can be added
    */
};
