#include "InvalidStringFormat.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;

const std::string InvalidStringFormat::MESSAGE = "invalid string format - "
	"required quotes";

InvalidStringFormat::InvalidStringFormat(void) :
	CompileException(MESSAGE)
{}
