#pragma once

#include "commands/command.hpp"

namespace lock
{

class LsCommand : public Command
{
public:
    LsCommand(Parser &parent);
    virtual ~LsCommand();

private:
    virtual void setup();
    virtual void handle_command() override;
};

}
