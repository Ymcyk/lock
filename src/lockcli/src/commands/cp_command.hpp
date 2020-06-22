#pragma once

#include "commands/command.hpp"

namespace lock
{

class CpCommand : public Command
{
public:
    CpCommand();
    virtual ~CpCommand();

    virtual void setup(Parser &app) override;

private:
    void parseComplete();
};

}
