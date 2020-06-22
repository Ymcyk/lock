#include "commands/rm_command.hpp"

#include <memory>
#include <iostream>

#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{

RmCommand::RmCommand() = default;

RmCommand::~RmCommand() = default;

void lock::RmCommand::setup(Parser &app)
{
    auto command = app.add_subcommand("rm", "Remove a credential");

    command.parse_complete_callback([this]{ parseComplete(); });
}

void RmCommand::parseComplete()
{
    std::cout << "rm completed\n";
}

template<>
Command_up createCommand<CommandType::Rm>()
{
    return std::make_unique<RmCommand>();
}

}
