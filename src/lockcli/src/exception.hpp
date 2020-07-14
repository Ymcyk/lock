#pragma once
#include "lock/exception.hpp"

namespace lock
{

class ParseException : public Exception
{
public:
    ParseException(std::string name, std::string msg,
                   ExitCodes exit_code = ExitCodes::Failure);
};

} // namespace lock
