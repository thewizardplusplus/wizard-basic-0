#include "LabelConflictWithConditionalJumps.h"

using namespace thewizard::nicole_compiler::exceptions;

const std::string LabelConflictWithConditionalJumps::MESSAGE = "label conflict "
	"with the conditional jumps";

LabelConflictWithConditionalJumps::LabelConflictWithConditionalJumps() :
	CompileException(MESSAGE)
{}
