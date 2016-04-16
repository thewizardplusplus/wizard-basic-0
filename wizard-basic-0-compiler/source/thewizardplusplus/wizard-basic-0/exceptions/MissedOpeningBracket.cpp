#include "MissedOpeningBracket.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;

const std::string MissedOpeningBracket::MESSAGE = "missed opening bracket";

MissedOpeningBracket::MissedOpeningBracket(void) :
	CompileException(MESSAGE)
{}
