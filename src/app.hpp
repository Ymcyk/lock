#ifndef APP_HPP
#define APP_HPP

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
    std::unique_ptr<Impl> impl;
};
}

#endif
