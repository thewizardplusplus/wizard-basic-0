#include "InvalidFunctionIdentifier.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string InvalidFunctionIdentifier::MESSAGE = "invalid function "
	"identifier \"%0%\"";

InvalidFunctionIdentifier::InvalidFunctionIdentifier(
	const std::string& identifier)
:
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
