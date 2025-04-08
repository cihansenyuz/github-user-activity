#include <iostream>
#include "inc/application.hpp"

int main(int argc, char **argv){
    if(argc == 1){
        std::cout << "re-run the app providing a github username"
        << "\ne.g. $ ./github_user_activity_fetcher cihansenyuz" << std::endl;
        return EXIT_FAILURE;
    }

    std::string username_to_be_fetched = argv[1];
    
    Application app(username_to_be_fetched);
    app.PrintEventStats();
    
    return EXIT_SUCCESS;
}