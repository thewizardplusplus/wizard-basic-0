#include "StatementCompiler.h"
#include "../utils/Formatter.h"
#include <stdexcept>

using namespace thewizard::nicole_compiler;
using namespace thewizard::utils;

const std::string StatementCompiler::INVALID_ARGUMENT_MESSAGE = "Unable to "
	"construct StatementCompiler(\"%0%\", \"%1%\") with null Compiler pointer.";

StatementCompiler::StatementCompiler(Compiler* compiler,
	const std::string& mark, const std::string& separator)
:
	compiler(compiler),
	mark(mark),
	separator(separator)
{
	if (compiler == NULL) {
		throw std::invalid_argument(Formatter(INVALID_ARGUMENT_MESSAGE)
			.setArgument(mark).setArgument(separator));
	}
}

StatementCompiler::~StatementCompiler(void) {}

Compiler* StatementCompiler::getCompiler(void) const {
	return compiler;
}

std::string StatementCompiler::getMark(void) const {
	return mark;
}

std::string StatementCompiler::getSeparator(void) const {
	return separator;
}
