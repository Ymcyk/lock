#include "app.hpp"

#include <iostream>

#include "exception.hpp"
#include "commands/parser.hpp"
#include "commands/command_factory.hpp"

namespace lock
{
struct App::Impl
{
    Impl();

    void addCommands();

    std::vector<Command_up> commands;
    Parser app;
};

App::Impl::Impl()
    : app{"lock"}
{
    app.require_subcommand(0, 1);
}

App::App() 
    : _impl{std::make_unique<Impl>()}
{ }

App::~App() = default;

int App::parse(int argc, char **argv)
{
    _impl->addCommands();

    try
    {
        _impl->app.parse(argc, argv);
    }
    catch(const ParseException &e)
    {
        return e.get_exit_code();
    }
    catch(const Exception &e)
    {
        std::cerr << e.what() << std::endl;
        return e.get_exit_code();
    }

    return EXIT_SUCCESS;
}

void App::Impl::addCommands()
{
    commands.push_back(createCommand<CommandType::Add>());
    commands.push_back(createCommand<CommandType::Ls>());

    for (auto &elem : commands)
    {
        elem->setup(app);
    }
}
}
