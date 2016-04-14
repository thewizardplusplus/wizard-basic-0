#include "InvalidFunctionIdentifier.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;
using namespace thewizardplusplus::utils;

const std::string InvalidFunctionIdentifier::MESSAGE = "invalid function "
	"identifier \"%0%\"";

InvalidFunctionIdentifier::InvalidFunctionIdentifier(
	const std::string& identifier)
:
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
