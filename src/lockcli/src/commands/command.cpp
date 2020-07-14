#include "command.hpp"

namespace lock
{

Command::Command(std::string name, std::string description, Parser &parent)
    : _parser{std::move(name), std::move(description)}
{
    _parser.set_command_handler([this] { handle_command(); });
    parent.add_subcommand(_parser);
}

} // namespace lock
