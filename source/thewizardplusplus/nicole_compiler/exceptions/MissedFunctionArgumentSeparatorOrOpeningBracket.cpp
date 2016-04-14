#include "MissedFunctionArgumentSeparatorOrOpeningBracket.h"

using namespace thewizard::nicole_compiler::exceptions;

const std::string MissedFunctionArgumentSeparatorOrOpeningBracket::MESSAGE =
	"missed function argument separator or opening bracket";

MissedFunctionArgumentSeparatorOrOpeningBracket
::MissedFunctionArgumentSeparatorOrOpeningBracket(void)
:
	CompileException(MESSAGE)
{}
