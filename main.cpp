#include "inc/githubrequester.hpp"
#include <iostream>

int main(){
    GitHubRequester ghr("cihansenyuz");
    ghr.MakeRequestToApi();
    std::string response = ghr.GetResponse();
    
    std::cout << response << std::endl;

    return 0;
}