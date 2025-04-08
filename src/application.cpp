#include "../inc/application.hpp"
#include "../inc/githubresponseparser.hpp"
#include <iostream>

Application::Application(const std::string &user_name)
    : gh_requester_{std::make_unique<GitHubRequester>(user_name)} {
        gh_requester_->MakeRequestToApi();
        std::string response = gh_requester_->GetResponse();

        try{
        events = GitHubResponseParser::Parse(response);
        }
        catch(const std::exception &e){
            std::cerr << "error: " << e.what() << std::endl;
        }
}

void Application::PrintEventStats() const{
    for(const auto &event : events){
        std::cout << event.date << " " << event.type
                    << "\n\trepository: " << event.repository << std::endl;
    }
}
