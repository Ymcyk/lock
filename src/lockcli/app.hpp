#pragma once

#include <memory>

namespace lock
{
class App
{
public:
    App();
    ~App();

    int parse(int argc, char **argv);

private:
    struct Impl;
    std::unique_ptr<Impl> _impl;
};
}
