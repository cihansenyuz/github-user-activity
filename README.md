# github-user-activity

A simple command line interface (CLI) to fetch the recent activity of a GitHub user and display it in the terminal.
Project includes working with APIs, handling JSON data, and building a simple CLI application.

Fetches the recent activity of the specified GitHub user using the GitHub API.
https://api.github.com/users/<username>/events

Displays the fetched activity in the terminal

## Dependencies

### 1- GCC and Make -> to compile source files

### 2- cmake 3.22 -> to build project

on ubuntu:
```bash
$ sudo apt update
$ sudo apt install cmake
```
on windows:

Go to https://cmake.org/download/ and download installer. Run the installer.

### 3- boost -> for tcp socket to send HTTP request

on ubuntu:
```bash
$ sudo apt update
$ sudo apt install libboost-all-dev
```
on windows:

Download Boost from boost.org. Extract the .zip file. On cmd.exe,
$ cd boost_1_84_0
$ bootstrap.bat
$ .\b2

### 4- OpenSSL -> for encripted HTTP request (GitHub API forces to use HTTPS)

on ubuntu:
```bash
$ sudo apt update
$ sudo apt install libssl-dev
```
on windows:

Seems quite complicated without package manager. So I decided not to mention :)

## How to create the executable

on ubuntu, go to the folder of the repository
then,
```bash
$ chmod +x rebuild.sh
$ mkdir build
$ cd build/
$ ../rebuild.sh
```

## How to use the app

Provide the GitHub username as an argument when running the CLI.
```bash
$ ./github_user_activity_fetcher kamranahmedse
```
### Example output

```bash
$ ./github_user_activity_fetcher cihansenyuz
Request sent...
2025-04-07T12:49:36Z PullRequestEvent
	repository: cihansenyuz/github-user-activity
2025-04-07T12:49:03Z CreateEvent
	repository: cihansenyuz/github-user-activity
2025-04-07T12:42:34Z PushEvent
	repository: cihansenyuz/github-user-activity
2025-04-07T12:31:56Z PushEvent
	repository: cihansenyuz/github-user-activity
2025-04-07T09:33:25Z PushEvent
	repository: cihansenyuz/github-user-activity
2025-04-07T08:24:51Z PushEvent
	repository: cihansenyuz/project_gym
2025-04-04T11:34:34Z PushEvent
	repository: cihansenyuz/github-user-activity
2025-04-04T08:08:49Z PushEvent
	repository: cihansenyuz/github-user-activity
2025-04-04T07:08:41Z PushEvent
	repository: cihansenyuz/github-user-activity
2025-03-26T06:41:38Z CreateEvent
	repository: cihansenyuz/github-user-activity
2025-03-26T06:35:06Z CreateEvent
	repository: cihansenyuz/github-user-activity
```
