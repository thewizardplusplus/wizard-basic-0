#include "UndefinedVariable.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string UndefinedVariable::MESSAGE = "undefined variable \"%0%\"";

UndefinedVariable::UndefinedVariable(const std::string& identifier) :
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
