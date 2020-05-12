#pragma once

#include <memory>

#include "commands/command.hpp"

namespace lock
{

class AddCommand : public Command
{
public:
    AddCommand();
    virtual ~AddCommand();

    virtual void setup(Parser &app) override;

private:
    struct Pimpl;
    std::unique_ptr<Pimpl> _pimpl;
};

}
