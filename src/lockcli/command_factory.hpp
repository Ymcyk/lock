#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include <memory>
#include "command.hpp"

namespace lock
{
enum class CommandType
{
    Add,
    Ls,
};

using Command_up = std::unique_ptr<Command>;

template<CommandType type>
Command_up createCommand();
}

#endif
