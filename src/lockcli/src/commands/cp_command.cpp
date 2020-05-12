#include "commands/cp_command.hpp"

#include <string>
#include <optional>
#include <iostream>

#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{

struct CpCommand::Pimpl
{
    void parseComplete();
};

CpCommand::CpCommand()
    : _pimpl{std::make_unique<Pimpl>()}
{

}

CpCommand::~CpCommand()
{
    
}

void lock::CpCommand::setup(Parser &app)
{
    auto command = app.add_subcommand("cp", "Copy a credential to the clipboard");

    command.parse_complete_callback([this]{ this->_pimpl->parseComplete(); });
}

void CpCommand::Pimpl::parseComplete()
{
    std::cout << "cp completed\n";
}

template<>
Command_up createCommand<CommandType::Cp>()
{
    return std::make_unique<CpCommand>();
}

}
