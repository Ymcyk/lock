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
    void setup();
    virtual void handle_command() override;
};

} // namespace lock
