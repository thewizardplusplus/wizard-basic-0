#include "LabelConflictWithConditionalJumps.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;

const std::string LabelConflictWithConditionalJumps::MESSAGE = "label conflict "
	"with the conditional jumps";

LabelConflictWithConditionalJumps::LabelConflictWithConditionalJumps() :
	CompileException(MESSAGE)
{}
