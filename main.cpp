#include "inc/githubrequester.hpp"
#include "inc/githubresponseparser.hpp"
#include <iostream>

int main(){
    GitHubRequester ghr("cihansenyuz");
    ghr.MakeRequestToApi();
    
    std::string response = ghr.GetResponse();
    auto events = GitHubResponseParser::Parse(response);

    for(const auto &event : events){
        std::cout << event.date << " " << event.type
                  << "/trepository: " << event.repository << std::endl;
    }

    return 0;
}