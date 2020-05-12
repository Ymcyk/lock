#pragma once

#include <memory>

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
    struct Pimpl;
    std::unique_ptr<Pimpl> _pimpl;
};

}
