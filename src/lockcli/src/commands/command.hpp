#pragma once

#include <string_view>

namespace lock
{

class Parser;

class Command
{
public:
    virtual ~Command() {}
    virtual void setup(Parser &app) = 0;
};

}
