#include "FailedOpenTemporaryFileException.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;
using namespace thewizardplusplus::utils;

const std::string FailedOpenTemporaryFileException::MESSAGE = "Unable to open "
	"temporary file \"%0%\".";

FailedOpenTemporaryFileException::FailedOpenTemporaryFileException(const std::
	string& filename)
:
	std::runtime_error(Formatter(MESSAGE).setArgument(filename))
{}
