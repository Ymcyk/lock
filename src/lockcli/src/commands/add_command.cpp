#include "commands/add_command.hpp"

#include <memory>
#include <iostream>

#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{

AddCommand::AddCommand() = default;

AddCommand::~AddCommand() = default;

void lock::AddCommand::setup(Parser &app)
{
    auto command = app.add_subcommand("add", "Add a credential");

    command.add_option("key", "Credential identifier").required();
    command.add_option_function("login", 
        [this](const std::string &arg){ _login = arg; }, "New credential login");

    command.parse_complete_callback([this]{ parseComplete(); });
}

void AddCommand::parseComplete()
{
    if (_login)
    {
        std::cout << "login passed\n";
    }
    else
    {
        std::cout << "TODO: get login from stdin\n";
    }
    

    std::cout << "add completed\n";
}

template<>
Command_up createCommand<CommandType::Add>()
{
    return std::make_unique<AddCommand>();
}

}
