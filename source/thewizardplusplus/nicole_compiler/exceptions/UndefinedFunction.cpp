#include "UndefinedFunction.h"
#include "../../utils/Formatter.h"

using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string UndefinedFunction::MESSAGE = "undefined function \"%0%\"";

UndefinedFunction::UndefinedFunction(const std::string& identifier) :
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
