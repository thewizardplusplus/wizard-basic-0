#include "IdentifierConflictWithFunction.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;
using namespace thewizardplusplus::utils;

const std::string IdentifierConflictWithFunction::MESSAGE = "identifier "
	"conflict with the function \"%0%\"";

IdentifierConflictWithFunction::IdentifierConflictWithFunction(
	const std::string& identifier)
:
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
