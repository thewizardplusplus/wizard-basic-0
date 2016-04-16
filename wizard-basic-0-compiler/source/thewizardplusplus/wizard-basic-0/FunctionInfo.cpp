#include "FunctionInfo.h"

using namespace thewizardplusplus::wizard_basic_0;

FunctionInfo::FunctionInfo(size_t number_of_arguments, bool return_value) :
	number_of_arguments(number_of_arguments),
	return_value(return_value)
{}

size_t FunctionInfo::getNumberOfArguments() const {
	return number_of_arguments;
}

bool FunctionInfo::hasReturnValue() const {
	return return_value;
}
