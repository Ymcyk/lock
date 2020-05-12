#include "commands/rm_command.hpp"

#include <string>
#include <optional>
#include <iostream>

#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{

struct RmCommand::Pimpl
{
    void parseComplete();
};

RmCommand::RmCommand()
    : _pimpl{std::make_unique<Pimpl>()}
{

}

RmCommand::~RmCommand()
{
    
}

void lock::RmCommand::setup(Parser &app)
{
    auto command = app.add_subcommand("rm", "Remove a credential");

    command.parse_complete_callback([this]{ this->_pimpl->parseComplete(); });
}

void RmCommand::Pimpl::parseComplete()
{
    std::cout << "rm completed\n";
}

template<>
Command_up createCommand<CommandType::Rm>()
{
    return std::make_unique<RmCommand>();
}

}
