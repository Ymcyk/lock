#pragma once

#include <string>
#include <optional>

#include "commands/command.hpp"

namespace lock
{

class AddCommand : public Command
{
public:
    AddCommand(Parser &parent);
    virtual ~AddCommand();

private:
    virtual void setup();
    virtual void handle_command() override;

private:
    std::string _key;
    std::optional<std::string> _login;
    std::optional<std::string> _password;
};

}
