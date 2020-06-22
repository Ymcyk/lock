#pragma once

#include <string>
#include <optional>

#include "commands/command.hpp"

namespace lock
{

class AddCommand : public Command
{
public:
    AddCommand();
    virtual ~AddCommand();

    virtual void setup(Parser &app) override;

private:
    void parseComplete();

    std::string _key;
    std::optional<std::string> _login;
    std::optional<std::string> _password;
};

}
