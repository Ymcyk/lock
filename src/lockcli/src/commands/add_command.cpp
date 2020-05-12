#include "commands/add_command.hpp"

#include <string>
#include <optional>
#include <iostream>

#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{

struct AddCommand::Pimpl
{
    void parseComplete();

    std::string key;
    std::optional<std::string> login;
    std::optional<std::string> password;
};

AddCommand::AddCommand()
    : _pimpl{std::make_unique<Pimpl>()}
{

}

AddCommand::~AddCommand()
{
    
}

void lock::AddCommand::setup(Parser &app)
{
    auto command = app.add_subcommand("add", "Add a credential");

    command.add_option("key", "Credential identifier").required();
    command.add_option_function("login", 
        [this](const std::string &arg){ _pimpl->login = arg; }, "New credential login");

    command.parse_complete_callback([this]{ this->_pimpl->parseComplete(); });
}

void AddCommand::Pimpl::parseComplete()
{
    if (login)
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
