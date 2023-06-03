#include "Exception.h"

#include <string>
#include <stdexcept>

Exception::Exception(const std::string& error) : std::runtime_error{ error.c_str() } {}
