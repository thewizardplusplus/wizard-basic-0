#include "MissedClosingBracket.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;

const std::string MissedClosingBracket::MESSAGE = "missed closing bracket";

MissedClosingBracket::MissedClosingBracket(void) :
	CompileException(MESSAGE)
{}
