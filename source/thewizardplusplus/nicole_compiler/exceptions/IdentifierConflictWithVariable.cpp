#include "IdentifierConflictWithVariable.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string IdentifierConflictWithVariable::MESSAGE = "identifier "
	"conflict with the variable \"%0%\"";

IdentifierConflictWithVariable::IdentifierConflictWithVariable(
	const std::string& identifier)
:
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
