#include "UndefinedVariable.h"
#include "../../utils/Formatter.h"

using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string UndefinedVariable::MESSAGE = "undefined variable \"%0%\"";

UndefinedVariable::UndefinedVariable(const std::string& identifier) :
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
