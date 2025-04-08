#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include "githubevent.hpp"

class GitHubResponseParser{
public:
    static std::vector<GitHubEvent> Parse(const std::string &response){
        nlohmann::json json_array;

        if(!json_array.is_array())
            throw std::runtime_error{"reponse is not a json array!"};

        for(const auto &json_object : json_array){
            GitHubEvent event;
            
            if(json_object.contains(GitHubEvent::type_field)
                && json_object[GitHubEvent::type_field].is_string()){
                    event.type = json_object[GitHubEvent::type_field];
            }
            else
                throw std::runtime_error{"invalid response: type field"};

            if(json_object.contains(GitHubEvent::repo_field)
                && json_object[GitHubEvent::repo_field].is_object()
                && json_object.contains(GitHubEvent::repo_name)
                && json_object[GitHubEvent::repo_name].is_string()){
                    event.repository = json_object[GitHubEvent::repo_name];
            }
            else
                throw std::runtime_error{"invalid response: repo field"};

            if(json_object.contains(GitHubEvent::date_field)
                && json_object[GitHubEvent::date_field].is_string()){
                    event.date = json_object[GitHubEvent::date_field];
            }
            else
                throw std::runtime_error{"invalid response: created_at field"};

        }
    }

private:
    GitHubResponseParser() = default;
};