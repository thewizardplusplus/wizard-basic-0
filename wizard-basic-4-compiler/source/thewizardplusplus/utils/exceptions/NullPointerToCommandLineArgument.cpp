#include "NullPointerToCommandLineArgument.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::utils::exceptions;
using namespace thewizardplusplus::utils;

const std::string NullPointerToCommandLineArgument::MESSAGE = "Null pointer to "
	"command line argument %0%.";

NullPointerToCommandLineArgument::NullPointerToCommandLineArgument(
	size_t number)
:
	std::runtime_error(Formatter(MESSAGE).setArgument(number))
{}
