#pragma once
#include <stdexcept>
#include <string>

// Represents internal exceptions
class Exception : public std::runtime_error {
public:
	Exception(const std::string& error);
};
