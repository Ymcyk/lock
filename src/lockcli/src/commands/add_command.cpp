#include "commands/add_command.hpp"

#include <memory>
#include <iostream>

#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{

AddCommand::AddCommand(Parser &parent) 
    : Command{"add", "Add a credential", parent}
{ }

AddCommand::~AddCommand() = default;

void lock::AddCommand::setup()
{
    _parser.add_option_function("key", 
                                [this](const std::string &arg){ _key = arg; }, 
                                "Credential identifier");
    _parser.add_option_function("login", 
                                [this](const std::string &arg){ _login = arg; }, 
                                "New credential login");
}

void AddCommand::handle_command()
{
    std::cout << "Key: " << _key << '\n';
    std::cout << "Login: " << _login.value_or("-- no login passed --") << '\n';
    std::cout << "TODO: add handler\n";
}

template<>
Command_up create_command<CommandType::Add>(Parser &parent)
{
    return std::make_unique<AddCommand>(parent);
}

}
