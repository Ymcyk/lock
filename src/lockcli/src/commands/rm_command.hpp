#pragma once

#include "commands/command.hpp"

namespace lock
{

class RmCommand : public Command
{
public:
    RmCommand();
    virtual ~RmCommand();

    virtual void setup(Parser &app) override;

private:
    void parse_complete();
};

}
