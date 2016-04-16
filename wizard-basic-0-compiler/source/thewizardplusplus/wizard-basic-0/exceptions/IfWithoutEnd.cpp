#include "IfWithoutEnd.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;

const std::string IfWithoutEnd::MESSAGE = "if without end";

IfWithoutEnd::IfWithoutEnd(void) :
	CompileException(MESSAGE)
{}
