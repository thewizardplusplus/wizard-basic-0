#include "UnknownStatement.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;

const std::string UnknownStatement::MESSAGE = "there is no compiler for that "
	"statement";

UnknownStatement::UnknownStatement(void) :
	CompileException(MESSAGE)
{}
