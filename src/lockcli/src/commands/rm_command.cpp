#include "commands/rm_command.hpp"

#include <iostream>
#include <memory>

#include "commands/command_factory.hpp"
#include "commands/parser.hpp"

namespace lock
{

RmCommand::RmCommand(Parser &parent)
    : Command{"rm", "Remove a credential", parent}
{
    setup();
}

RmCommand::~RmCommand() = default;

void lock::RmCommand::setup() {}

void RmCommand::handle_command() { std::cout << "TODO: rm handler\n"; }

template <>
Command_up create_command<CommandType::Rm>(Parser &parent)
{
    return std::make_unique<RmCommand>(parent);
}

} // namespace lock
