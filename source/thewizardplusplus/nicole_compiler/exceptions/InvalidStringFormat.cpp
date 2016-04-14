#include "InvalidStringFormat.h"

using namespace thewizard::nicole_compiler::exceptions;

const std::string InvalidStringFormat::MESSAGE = "invalid string format - "
	"required quotes";

InvalidStringFormat::InvalidStringFormat(void) :
	CompileException(MESSAGE)
{}
