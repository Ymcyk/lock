#pragma once

#include <string_view>

#include "commands/parser.hpp"

namespace lock
{

class Parser;

class Command
{
public:
    Command(std::string name, std::string description, Parser &parent);
    virtual ~Command() { }

protected:
    virtual void handle_command() = 0;

protected:
    Parser _parser;
};

}
