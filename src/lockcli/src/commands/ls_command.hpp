#pragma once

#include "commands/command.hpp"

namespace lock
{

class LsCommand : public Command
{
public:
    LsCommand();
    virtual ~LsCommand();

    virtual void setup(Parser &app) override;

private:
    void parse_complete();
};

}
