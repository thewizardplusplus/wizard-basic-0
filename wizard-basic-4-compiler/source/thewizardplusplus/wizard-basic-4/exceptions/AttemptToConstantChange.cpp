#include "AttemptToConstantChange.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;
using namespace thewizardplusplus::utils;

const std::string AttemptToConstantChange::MESSAGE = "an attempt to change of "
	"the constant %0%";

AttemptToConstantChange::AttemptToConstantChange(const std::string& identifier)
:
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
