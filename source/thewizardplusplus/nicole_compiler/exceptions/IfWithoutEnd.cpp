#include "IfWithoutEnd.h"

using namespace thewizard::nicole_compiler::exceptions;

const std::string IfWithoutEnd::MESSAGE = "if without end";

IfWithoutEnd::IfWithoutEnd(void) :
	CompileException(MESSAGE)
{}
