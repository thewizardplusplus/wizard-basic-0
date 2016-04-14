#include "UnknownCommandLineOption.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string UnknownCommandLineOption::MESSAGE = "Unknown option \"%0%\".";

UnknownCommandLineOption::UnknownCommandLineOption(const std::string& option) :
	std::runtime_error(Formatter(MESSAGE).setArgument(option))
{}
