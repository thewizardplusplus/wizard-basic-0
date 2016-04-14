#include "MissedOpeningBracket.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;

const std::string MissedOpeningBracket::MESSAGE = "missed opening bracket";

MissedOpeningBracket::MissedOpeningBracket(void) :
	CompileException(MESSAGE)
{}
