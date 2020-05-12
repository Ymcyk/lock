#include "commands/parser.hpp"

#include <memory>

#include "exception.hpp"
#include "CLI11.hpp"

namespace lock
{

// Parser Impl methods

struct Parser::Impl
{
    Impl(std::string name, std::string description);
    explicit Impl(CLI::App_p app);

    void addCommands();

    CLI::App_p app{};
};

Parser::Impl::Impl(std::string name, std::string description)
    : app{std::make_shared<CLI::App>(std::move(description), std::move(name))}
{

}

Parser::Impl::Impl(CLI::App_p app)
    : app{app}
{

}

// Option Impl methods

struct Option::Impl
{
    explicit Impl(CLI::Option *option);

    CLI::Option *_option;
};

Option::Impl::Impl(CLI::Option *option)
    : _option{option}
{

}

// Parser methods

Parser::Parser(std::string name, std::string description)
    : _impl{std::make_unique<Impl>(std::move(name), std::move(description))}
{

}

Parser::Parser(Impl_p impl)
    : _impl{std::move(impl)}
{

}

Parser::~Parser()
{

}

void Parser::parse(int argc, const char *const *argv)
{
    try
    {
        _impl->app->parse(argc, argv);
    }
    catch(const CLI::ParseError &e)
    {
        auto error_code = _impl->app->exit(e);
        throw ParseException(e.get_name(), std::string());
    }
}

Parser& Parser::require_subcommand(std::size_t min, std::size_t max)
{
    _impl->app->require_subcommand(min, max);

    return *this;
}

Parser Parser::add_subcommand(std::string subcommand_name, std::string subcommand_description)
{
    auto sub = std::make_shared<CLI::App>(std::move(subcommand_description), std::move(subcommand_name));
    auto impl = std::make_unique<Parser::Impl>(sub);

    _impl->app->add_subcommand(sub);

    return Parser{std::move(impl)};
}

Option Parser::add_option(std::string name, std::string description)
{
    auto option = _impl->app->add_option(std::move(name), description);
    auto impl = std::make_unique<Option::Impl>(option);

    return Option{std::move(impl)};
}

Option Parser::add_option_function(std::string name, const Parser::OptionCallback &func, std::string description)
{
    auto option = _impl->app->add_option_function(std::move(name), func, std::move(description));
    auto impl = std::make_unique<Option::Impl>(option);
    
    return Option{std::move(impl)};
}

Parser& Parser::parse_complete_callback(std::function<void ()> callback)
{
    _impl->app->parse_complete_callback(callback);

    return *this;
}

// Option methods

Option::Option(Impl_p impl)
    : _impl{std::move(impl)}
{

}

Option::~Option()
{

}

Option& Option::required(bool value)
{
    _impl->_option->required(value);
    return *this;
}

}
