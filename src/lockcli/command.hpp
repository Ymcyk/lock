#pragma once

#include <string_view>

namespace CLI
{

class App;

}

namespace lock
{

class Command
{
public:
    virtual ~Command() {}
    virtual void setup(CLI::App &app) = 0;
};

}
