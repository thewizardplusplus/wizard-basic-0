#include "NullPointerToArrayOfCommandLineArguments.h"

using namespace thewizardplusplus::utils::exceptions;

const std::string NullPointerToArrayOfCommandLineArguments::MESSAGE = "Null "
	"pointer to command line arguments.";

NullPointerToArrayOfCommandLineArguments
	::NullPointerToArrayOfCommandLineArguments(void)
:
	std::runtime_error(MESSAGE)
{}
