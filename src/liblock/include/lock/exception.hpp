#pragma once

#include <stdexcept>

namespace lock
{

enum class ExitCodes
{
    Success = 0,
    Failure = 1
};

class Exception : public std::runtime_error {
public:
    Exception(std::string name, std::string msg, ExitCodes exit_code = ExitCodes::Failure);

    int get_exit_code() const;
    std::string get_name() const;

private:
    int actual_exit_code;
    std::string error_name{"Error"};
};

}
