#include "app.hpp"

#include <iostream>

#include "exception.hpp"
#include "commands/parser.hpp"
#include "commands/command_factory.hpp"
#include "lock/version.hpp"

namespace lock
{
struct App::Impl
{
    Impl();

    void setup();
    void parse(int argc, char **argv);
    template<CommandType type>
    void addCommand()
    {
        createCommand<type>()->setup(app);
    }
    void addVersion();

    Parser app;
};

App::Impl::Impl()
    : app{"lock"}
{
    app.require_subcommand(0, 1);
}

void App::Impl::parse(int argc, char **argv)
{
    app.parse(argc, argv);
}

void App::Impl::addVersion()
{
    app.add_flag_callback("-v,--version", [](){ std::cout << Version::getString() << '\n'; }, "Show version");
}

void App::Impl::setup()
{
    addVersion();

    addCommand<CommandType::Add>();
    addCommand<CommandType::Ls>();
    addCommand<CommandType::Rm>();
    addCommand<CommandType::Cp>();
}

App::App() 
    : _impl{std::make_unique<Impl>()}
{ }

App::~App() = default;

int App::parse(int argc, char **argv)
{
    _impl->setup();

    try
    {
        _impl->parse(argc, argv);
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

}
