#include "console.hpp"
#ifdef WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

namespace lock
{

Console::Console(std::ostream &out, std::istream &in) : _out{out}, _in{in} {}

std::string Console::get_login()
{
    std::string input;

    _out << "Login: ";
    std::getline(_in, input);

    return input;
}

std::string Console::get_password()
{
    std::string input;

    _out << "Password: ";

    set_stdin_echo(false);
    std::getline(_in, input);
    set_stdin_echo(true);

    _out << '\n';

    return input;
}

void Console::set_stdin_echo(bool enable)
{
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);

    if (enable)
    {
        mode |= ENABLE_ECHO_INPUT;
    }
    else
    {
        mode &= ~ENABLE_ECHO_INPUT;
    }

    SetConsoleMode(hStdin, mode);
#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);

    if (enable)
    {
        tty.c_lflag |= ECHO;
    }
    else
    {
        tty.c_lflag &= ~ECHO;
    }

    (void)tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

} // namespace lock