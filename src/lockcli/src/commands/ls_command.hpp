#pragma once

#include <memory>

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
    struct Pimpl;
    std::unique_ptr<Pimpl> _pimpl;
};

}
