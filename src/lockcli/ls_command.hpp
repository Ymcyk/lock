#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include <memory>

#include "command.hpp"

namespace lock
{

class LsCommand : public Command
{
public:
    LsCommand();
    virtual ~LsCommand();

    virtual void setup(CLI::App &app) override;

private:
    struct Pimpl;
    std::unique_ptr<Pimpl> _pimpl;
};

}

#endif
