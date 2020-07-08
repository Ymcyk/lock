#pragma once

#include "commands/command.hpp"

namespace lock
{

class RmCommand : public Command
{
public:
    RmCommand(Parser &parent);
    virtual ~RmCommand();

private:
    virtual void setup();
    virtual void handle_command() override;
};

}
