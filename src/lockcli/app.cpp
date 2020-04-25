#include "app.hpp"
#include "3rdparty/CLI11.hpp"

namespace lock
{
struct App::Impl
{
    Impl();

    void setupCommands();
    void parse(int argc, char **argv);

    void addCommand();
    void lsCommand();
    void rmCommand();

    CLI::App app{};
};

App::Impl::Impl()
{
    app.name("lock")->
        require_subcommand(0, 1);
}

void App::Impl::setupCommands()
{
    addCommand();
    lsCommand();
    rmCommand();
}

void App::Impl::addCommand()
{
    app.add_subcommand("add", "Add a credential");
}

void App::Impl::lsCommand()
{
    app.add_subcommand("ls", "List all credentials");
}

void App::Impl::rmCommand()
{
    app.add_subcommand("rm", "Remove a credential");
}

App::App() 
    : impl{std::make_unique<Impl>()}
{ }

App::~App() = default;

int App::parse(int argc, char **argv)
{
    impl->setupCommands();

    CLI11_PARSE(impl->app, argc, argv);

    for (const auto &sub : impl->app.get_subcommands())
    {
        std::cout << sub->get_name() << '\n';
    }

    return EXIT_SUCCESS;
}
}
