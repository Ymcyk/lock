#include "commands/add_command.hpp"

#include <iostream>
#include <memory>

#include "commands/command_factory.hpp"
#include "commands/parser.hpp"

namespace lock
{

AddCommand::AddCommand(Parser &parent, Console console)
    : Command{"add", "Add a credential", parent}, _console{std::move(console)}
{
    setup();
}

AddCommand::~AddCommand() = default;

void lock::AddCommand::setup()
{
    _parser.add_option_function(
        "key", [this](const std::string &arg) { _key = arg; },
        "Credential identifier");
    _parser.add_option_function(
        "login", [this](const std::string &arg) { _login = arg; },
        "New credential login");
}

void AddCommand::get_user_input()
{
    if (!_login)
    {
        _login = _console.get_login();
    }

    if (!_password)
    {
        _password = _console.get_password();
    }
}

void AddCommand::handle_command()
{
    get_user_input();
    std::cout << _key << '|' << _login.value() << '|' << _password.value()
              << '\n';
}

template <>
Command_up create_command<CommandType::Add>(Parser &parent)
{
    return std::make_unique<AddCommand>(parent);
}

} // namespace lock
