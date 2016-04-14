#include "UnknownExpressionToken.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string UnknownExpressionToken::MESSAGE = "unknown expression token "
	"\"%0%\"";

UnknownExpressionToken::UnknownExpressionToken(const std::string& token) :
	CompileException(Formatter(MESSAGE).setArgument(token))
{}
