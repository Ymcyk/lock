#include "commands/ls_command.hpp"

#include <memory>
#include <iostream>

#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{

LsCommand::LsCommand() = default;

LsCommand::~LsCommand() = default;

void lock::LsCommand::setup(Parser &app)
{
    auto command = app.add_subcommand("ls", "List all credentials");

    command.parse_complete_callback([this]{ parseComplete(); });
}

void LsCommand::parseComplete()
{
    std::cout << "ls completed\n";
}

template<>
Command_up createCommand<CommandType::Ls>()
{
    return std::make_unique<LsCommand>();
}

}
