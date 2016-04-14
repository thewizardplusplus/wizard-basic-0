#include "IfWithoutEnd.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;

const std::string IfWithoutEnd::MESSAGE = "if without end";

IfWithoutEnd::IfWithoutEnd(void) :
	CompileException(MESSAGE)
{}
