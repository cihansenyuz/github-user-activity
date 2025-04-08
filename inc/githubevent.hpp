#pragma once

#include <string>

struct GitHubEvent{
    std::string type;
    std::string repository;
    std::string date;
    /*
    ... more fields can be added
    */

   static constexpr char *type_field = "type";
   static constexpr char *repo_field = "repo";
   static constexpr char *repo_name = "name";
   static constexpr char *date_field = "created_at";
};
