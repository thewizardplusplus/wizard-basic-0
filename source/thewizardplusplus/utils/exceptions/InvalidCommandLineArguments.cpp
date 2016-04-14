#include "InvalidCommandLineArguments.h"

using namespace thewizard::utils::exceptions;

const std::string InvalidCommandLineArguments::MESSAGE = "Invalid command line "
	"arguments.";

InvalidCommandLineArguments::InvalidCommandLineArguments(void) :
	std::runtime_error(MESSAGE)
{}
