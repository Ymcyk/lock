#include "commands/ls_command.hpp"

#include <memory>
#include <iostream>

#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{

LsCommand::LsCommand(Parser &parent)
    : Command{"ls", "List all credentials", parent}
{
    setup();
}

LsCommand::~LsCommand() = default;

void lock::LsCommand::setup()
{

}

void LsCommand::handle_command()
{
    std::cout << "TODO: ls handler\n";
}

template<>
Command_up create_command<CommandType::Ls>(Parser &parent)
{
    return std::make_unique<LsCommand>(parent);
}

}
