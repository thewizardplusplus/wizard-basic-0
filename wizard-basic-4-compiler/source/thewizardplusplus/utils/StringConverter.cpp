#include "StringConverter.h"

using namespace thewizardplusplus::utils;

std::string StringConverter::convert(const char* value) {
	return convert(std::string(value));
}

std::string StringConverter::convert(const std::string& value) {
	return value;
}
