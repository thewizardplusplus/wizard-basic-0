#include "UndefinedFunction.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;
using namespace thewizardplusplus::utils;

const std::string UndefinedFunction::MESSAGE = "undefined function \"%0%\"";

UndefinedFunction::UndefinedFunction(const std::string& identifier) :
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
