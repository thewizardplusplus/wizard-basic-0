#include "MissedOpeningBracket.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;

const std::string MissedOpeningBracket::MESSAGE = "missed opening bracket";

MissedOpeningBracket::MissedOpeningBracket(void) :
	CompileException(MESSAGE)
{}
