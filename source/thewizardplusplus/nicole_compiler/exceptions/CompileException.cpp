#include "CompileException.h"
#include "../../utils/Formatter.h"

using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string CompileException::MESSAGE = "Compile exception on line %1%: "
	"%0%.";

CompileException::CompileException(const std::string& message) :
	std::runtime_error(""),
	line_number(0)
{
	this->message = Formatter(MESSAGE).setArgument(message).toString();
}

CompileException::~CompileException(void) throw() {}

const char* CompileException::what(void) const throw() {
	return Formatter(message).skipArgument().setArgument(line_number);
}

unsigned long int CompileException::getLineNumber(void) const {
	return line_number;
}

void CompileException::setLineNumber(unsigned long int line_number) {
	this->line_number = line_number;
}
