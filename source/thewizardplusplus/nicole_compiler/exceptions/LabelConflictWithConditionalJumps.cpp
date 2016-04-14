#include "LabelConflictWithConditionalJumps.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;

const std::string LabelConflictWithConditionalJumps::MESSAGE = "label conflict "
	"with the conditional jumps";

LabelConflictWithConditionalJumps::LabelConflictWithConditionalJumps() :
	CompileException(MESSAGE)
{}
