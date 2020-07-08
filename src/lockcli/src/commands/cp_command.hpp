#pragma once

#include "commands/command.hpp"

namespace lock
{

class CpCommand : public Command
{
public:
    CpCommand(Parser &parent);
    virtual ~CpCommand();

private:
    virtual void setup();
    virtual void handle_command() override;
};

}
