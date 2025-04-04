cmake_minimum_required(VERSION 3.22)

project(github_user_activity_fetcher VERSION 0.1 LANGUAGES CXX)

set(PROJECT_SOURCES main.cpp
            src/requester.cpp
            
            inc/irequester.hpp
            inc/requester.hpp)

add_executable(github_user_activity_fetcher ${PROJECT_SOURCES})