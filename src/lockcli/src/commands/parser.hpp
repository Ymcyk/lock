#pragma once

#include <functional>
#include <string>
#include <memory>

namespace lock
{

class Option
{
public:
    Option& required(bool value = true);
    ~Option();

    friend class Parser;

private:
    struct Impl;
    using Impl_p = std::unique_ptr<Impl>;
    Option(Impl_p impl);

    Impl_p _impl;
};

class Parser
{
public:
    explicit Parser(std::string name, std::string description = "");
    ~Parser();

    using OptionCallback = std::function<void(const std::string &)>;
    using FlagCallback = std::function<void(void)>;

    void parse(int argc, const char *const *argv);
    Parser& require_subcommand(std::size_t min, std::size_t max);
    Parser add_subcommand(std::string subcommand_name, std::string subcommand_description);
    Option add_flag(std::string name, std::string description);
    Option add_flag_callback(std::string name, FlagCallback function, std::string description = "");
    Option add_option(std::string name, std::string description);
    Option add_option_function(std::string name, const OptionCallback &func, std::string description);
    Parser& parse_complete_callback(std::function<void ()> callback);

private:
    struct Impl;
    using Impl_p = std::unique_ptr<Impl>;
    Parser(Impl_p impl);

    Impl_p _impl;
};

}
