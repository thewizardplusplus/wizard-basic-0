#include "MissedClosingBracket.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;

const std::string MissedClosingBracket::MESSAGE = "missed closing bracket";

MissedClosingBracket::MissedClosingBracket(void) :
	CompileException(MESSAGE)
{}
