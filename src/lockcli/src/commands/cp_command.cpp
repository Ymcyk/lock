#include "commands/cp_command.hpp"

#include <iostream>
#include <memory>

#include "commands/command_factory.hpp"
#include "commands/parser.hpp"

namespace lock
{

CpCommand::CpCommand(Parser &parent)
    : Command{"cp", "Copy a credential to the clipboard", parent}
{
    setup();
}

CpCommand::~CpCommand() = default;

void lock::CpCommand::setup() {}

void CpCommand::handle_command() { std::cout << "TODO: cp handler\n"; }

template <>
Command_up create_command<CommandType::Cp>(Parser &parent)
{
    return std::make_unique<CpCommand>(parent);
}

} // namespace lock
