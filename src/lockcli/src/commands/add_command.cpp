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

    command.add_option_function("key", 
                                [this](const std::string &arg){ _key = arg; }, 
                                "Credential identifier");
    command.add_option_function("login", 
                                [this](const std::string &arg){ _login = arg; }, 
                                "New credential login");

    command.parse_complete_callback([this]{ parse_complete(); });
}

void AddCommand::parse_complete()
{
    std::cout << "Key: " << _key << '\n';
    std::cout << "Login: " << _login.value_or("-- no login passed --") << '\n';
}

template<>
Command_up create_command<CommandType::Add>()
{
    return std::make_unique<AddCommand>();
}

}
