#include "exception.hpp"

namespace lock
{

ParseException::ParseException(std::string name, std::string msg,
                               ExitCodes exit_code)
    : Exception(std::move(name), std::move(msg), exit_code)
{
}

} // namespace lock
