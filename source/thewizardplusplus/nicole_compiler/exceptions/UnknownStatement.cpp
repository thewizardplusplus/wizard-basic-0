#include "UnknownStatement.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;

const std::string UnknownStatement::MESSAGE = "there is no compiler for that "
	"statement";

UnknownStatement::UnknownStatement(void) :
	CompileException(MESSAGE)
{}
