#pragma once

#include <iostream>
#include <string>

namespace lock
{
class Console
{
public:
    Console(std::ostream &out = std::cout, std::istream &in = std::cin);

    std::string get_login();
    std::string get_password();

private:
    void set_stdin_echo(bool enable);

private:
    std::ostream &_out;
    std::istream &_in;
};
} // namespace lock
