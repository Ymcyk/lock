#pragma once

#include <memory>
#include "commands/command.hpp"

namespace lock
{
enum class CommandType
{
    Add,
    Ls,
    Rm,
    Cp,
};

using Command_up = std::unique_ptr<Command>;

template<CommandType type>
Command_up create_command();
}
