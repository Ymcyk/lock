#pragma once

#include <optional>
#include <string>

#include "commands/command.hpp"
#include "io/console.hpp"

namespace lock
{

class AddCommand : public Command
{
public:
    AddCommand(Parser &parent, Console console = {});
    virtual ~AddCommand();

private:
    void setup();
    void get_user_input();
    virtual void handle_command() override;

private:
    Console _console;
    std::string _key;
    std::optional<std::string> _login;
    std::optional<std::string> _password;
};

} // namespace lock
