#pragma once

#include <memory>

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
    struct Pimpl;
    std::unique_ptr<Pimpl> _pimpl;
};

}
