#pragma once

#include <string>

struct GitHubEvent{
    std::string type;
    std::string repository;
    std::string date;
    /*
    ... more fields can be added
    */

   static constexpr const char *type_field = "type";
   static constexpr const char *repo_field = "repo";
   static constexpr const char *repo_name = "name";
   static constexpr const char *date_field = "created_at";
};
