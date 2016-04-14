#include "CompileException.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;
using namespace thewizardplusplus::utils;

const std::string CompileException::MESSAGE = "Compile exception on line %1%: "
	"%0%.";

CompileException::CompileException(const std::string& message) :
	std::runtime_error(""),
	line_number(0)
{
	this->message = Formatter(MESSAGE).setArgument(message);
}

CompileException::~CompileException(void) throw() {}

const char* CompileException::what(void) const throw() {
	return Formatter(message).skipArgument().setArgument(line_number).toString()
		.c_str();
}

void CompileException::setLineNumber(unsigned long int line_number) {
	this->line_number = line_number;
}
