#include "commands/cp_command.hpp"

#include <memory>
#include <iostream>

#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{

CpCommand::CpCommand() = default;

CpCommand::~CpCommand() = default;

void lock::CpCommand::setup(Parser &app)
{
    auto command = app.add_subcommand("cp", "Copy a credential to the clipboard");

    command.parse_complete_callback([this]{ parse_complete(); });
}

void CpCommand::parse_complete()
{
    std::cout << "cp completed\n";
}

template<>
Command_up create_command<CommandType::Cp>()
{
    return std::make_unique<CpCommand>();
}

}
