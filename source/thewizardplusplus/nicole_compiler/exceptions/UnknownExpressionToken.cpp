#include "UnknownExpressionToken.h"
#include "../../utils/Formatter.h"

using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string UnknownExpressionToken::MESSAGE = "unknown expression token "
	"\"%0%\"";

UnknownExpressionToken::UnknownExpressionToken(const std::string& token) :
	CompileException(Formatter(MESSAGE).setArgument(token))
{}
