#include "lock/exception.hpp"

namespace lock
{

Exception::Exception(std::string name, std::string msg, ExitCodes exit_code)
    : runtime_error(msg), actual_exit_code(static_cast<int>(exit_code)),
      error_name(std::move(name))
{
}

int Exception::get_exit_code() const { return actual_exit_code; }

std::string Exception::get_name() const { return error_name; }

} // namespace lock
