#include "UnknownExpressionToken.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;
using namespace thewizardplusplus::utils;

const std::string UnknownExpressionToken::MESSAGE = "unknown expression token "
	"\"%0%\"";

UnknownExpressionToken::UnknownExpressionToken(const std::string& token) :
	CompileException(Formatter(MESSAGE).setArgument(token))
{}
