#include "InvalidNumberOfCodeLineParts.h"

using namespace thewizard::nicole_compiler::exceptions;

const std::string InvalidNumberOfCodeLineParts::MESSAGE = "invalid number of "
	"code line parts";

InvalidNumberOfCodeLineParts::InvalidNumberOfCodeLineParts(void) :
	CompileException(MESSAGE)
{}
