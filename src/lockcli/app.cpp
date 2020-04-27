#include "app.hpp"
#include "3rdparty/CLI11.hpp"
#include "command_factory.hpp"
#include <vector>

namespace lock
{
struct App::Impl
{
    Impl();

    void addCommands();

    std::vector<Command_up> commands;
    CLI::App app{};
};

App::Impl::Impl()
{
    app.name("lock")->
        require_subcommand(0, 1);
}

App::App() 
    : _impl{std::make_unique<Impl>()}
{ }

App::~App() = default;

int App::parse(int argc, char **argv)
{
    _impl->addCommands();

    CLI11_PARSE(_impl->app, argc, argv);

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
