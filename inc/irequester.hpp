#pragma once

#include <string>

class IRequester{
public:
    virtual void Request() = 0;
    virtual void CreateRequest() = 0;
    virtual void ProcessResponse() = 0;
    virtual const std::string& GetResponse() const = 0;
};