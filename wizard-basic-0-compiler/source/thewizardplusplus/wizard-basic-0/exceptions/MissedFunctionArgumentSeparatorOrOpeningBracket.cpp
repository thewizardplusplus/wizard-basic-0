#include "MissedFunctionArgumentSeparatorOrOpeningBracket.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;

const std::string MissedFunctionArgumentSeparatorOrOpeningBracket::MESSAGE =
	"missed function argument separator or opening bracket";

MissedFunctionArgumentSeparatorOrOpeningBracket
::MissedFunctionArgumentSeparatorOrOpeningBracket(void)
:
	CompileException(MESSAGE)
{}
