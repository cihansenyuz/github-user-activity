cmake_minimum_required(VERSION 3.22)
project(github_user_activity_fetcher VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system thread)
find_package(OpenSSL REQUIRED)

set(PROJECT_SOURCES main.cpp
            src/requester.cpp
            src/githubrequester.cpp
            
            inc/irequester.hpp
            inc/requester.hpp
            inc/githubrequester.hpp
    )

add_executable(github_user_activity_fetcher ${PROJECT_SOURCES})

target_link_libraries(github_user_activity_fetcher PRIVATE
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
)