#include "ls_command.hpp"
#include <string>
#include <optional>
#include "3rdparty/CLI11.hpp"
#include "command_factory.hpp"

namespace lock
{

struct LsCommand::Pimpl
{
    void parseComplete();

    std::string key;
    std::optional<std::string> login;
    std::optional<std::string> password;
};

LsCommand::LsCommand()
    : _pimpl{std::make_unique<Pimpl>()}
{

}

LsCommand::~LsCommand()
{
    
}

void lock::LsCommand::setup(CLI::App &app)
{
    auto command = app.add_subcommand("ls", "List all credentials");

    command->parse_complete_callback([this]{ this->_pimpl->parseComplete(); });
}

void LsCommand::Pimpl::parseComplete()
{
    std::cout << "ls completed\n";
}

template<>
Command_up createCommand<CommandType::Ls>()
{
    return std::make_unique<LsCommand>();
}

}
