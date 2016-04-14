#include "LabelConflictWithOtherLabel.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string LabelConflictWithOtherLabel::MESSAGE = "label conflict with "
	"the other label \"%0%\"";

LabelConflictWithOtherLabel::LabelConflictWithOtherLabel(
	const std::string& identifier)
:
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
