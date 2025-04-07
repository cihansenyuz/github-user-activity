# github-user-activity

A simple command line interface (CLI) to fetch the recent activity of a GitHub user and display it in the terminal.
Project includes working with APIs, handling JSON data, and building a simple CLI application.

## Dependencies

1- GCC and Make -> to compile source files

2- cmake 3.22 -> to build project

on ubuntu:

$ sudo apt update
$ sudo apt install cmake

on windows:

Go to https://cmake.org/download/ and download installer. Run the installer.

3- boost -> for tcp socket to send HTTP request

on ubuntu:

$ sudo apt update
$ sudo apt install libboost-all-dev

on windows:

Download Boost from boost.org. Extract the .zip file. On cmd.exe,
$ cd boost_1_84_0
$ bootstrap.bat
$ .\b2

4- OpenSSL -> for encripted HTTP request (GitHub API forces to use HTTPS)

on ubuntu:

sudo apt update
sudo apt install libssl-dev

on windows:

Seems quite complicated without package manager. So I decided not to mention :)

## How to use

Provide the GitHub username as an argument when running the CLI.

Fetch the recent activity of the specified GitHub user using the GitHub API.
https://api.github.com/users/<username>/events

Display the fetched activity in the terminal

