#include "EndWithoutIf.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;

const std::string EndWithoutIf::MESSAGE = "end without if";

EndWithoutIf::EndWithoutIf(void) :
	CompileException(MESSAGE)
{}
