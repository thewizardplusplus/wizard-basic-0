#include "MissedClosingBracket.h"

using namespace thewizard::nicole_compiler::exceptions;

const std::string MissedClosingBracket::MESSAGE = "missed closing bracket";

MissedClosingBracket::MissedClosingBracket(void) :
	CompileException(MESSAGE)
{}
