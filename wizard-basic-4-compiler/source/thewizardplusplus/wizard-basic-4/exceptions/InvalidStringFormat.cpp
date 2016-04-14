#include "InvalidStringFormat.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;

const std::string InvalidStringFormat::MESSAGE = "invalid string format - "
	"required quotes";

InvalidStringFormat::InvalidStringFormat(void) :
	CompileException(MESSAGE)
{}
