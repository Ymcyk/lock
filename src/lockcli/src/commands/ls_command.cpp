#include "commands/ls_command.hpp"

#include <iostream>
#include <memory>

#include "commands/command_factory.hpp"
#include "commands/parser.hpp"

namespace lock
{

LsCommand::LsCommand(Parser &parent)
    : Command{"ls", "List all credentials", parent}
{
    setup();
}

LsCommand::~LsCommand() = default;

void lock::LsCommand::setup() {}

void LsCommand::handle_command() { std::cout << "TODO: ls handler\n"; }

template <>
Command_up create_command<CommandType::Ls>(Parser &parent)
{
    return std::make_unique<LsCommand>(parent);
}

} // namespace lock
