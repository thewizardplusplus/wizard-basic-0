#include "EndWithoutIf.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;

const std::string EndWithoutIf::MESSAGE = "end without if";

EndWithoutIf::EndWithoutIf(void) :
	CompileException(MESSAGE)
{}
