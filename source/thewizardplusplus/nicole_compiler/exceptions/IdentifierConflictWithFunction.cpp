#include "IdentifierConflictWithFunction.h"
#include "../../utils/Formatter.h"

using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string IdentifierConflictWithFunction::MESSAGE = "identifier "
	"conflict with the function \"%0%\"";

IdentifierConflictWithFunction::IdentifierConflictWithFunction(
	const std::string& identifier)
:
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
