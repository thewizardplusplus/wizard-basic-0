#include "InvalidNumberOfCodeLineParts.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;

const std::string InvalidNumberOfCodeLineParts::MESSAGE = "invalid number of "
	"code line parts";

InvalidNumberOfCodeLineParts::InvalidNumberOfCodeLineParts(void) :
	CompileException(MESSAGE)
{}
