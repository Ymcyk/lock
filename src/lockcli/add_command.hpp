#pragma once

#include <memory>

#include "command.hpp"

namespace lock
{

class AddCommand : public Command
{
public:
    AddCommand();
    virtual ~AddCommand();

    virtual void setup(CLI::App &app) override;

private:
    struct Pimpl;
    std::unique_ptr<Pimpl> _pimpl;
};

}
