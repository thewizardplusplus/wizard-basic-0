#include "TestStatement.h"
#include "../utils/Console.h"
#include "../utils/Formatter.h"

using namespace thewizard::nicole_compiler;
using namespace thewizard::utils;

const std::string TestStatement::FIRST_MESSAGE =   "Find TestStatement("
	"\"%0%\", \"%1%\").";
const std::string TestStatement::DETAIL_ITEM =     "\"%0%\", ";
const std::string TestStatement::DETAILS_MESSAGE = "Obtained following %0% "
	"parts of the line: %1%.";

TestStatement::TestStatement(Compiler* compiler, const std::string& mark,
	const std::string& separator)
:
	StatementCompiler(compiler, mark, separator)
{}

void TestStatement::compile(const StringList& code_line_parts) {
	Console::information() << (Formatter(FIRST_MESSAGE) << getMark() <<
		getSeparator());

	std::string details;
	StringList::const_iterator i = code_line_parts.begin();
	for (; i != code_line_parts.end(); ++i) {
		details += Formatter(DETAIL_ITEM).setArgument(*i).toString();
	}
	if (!code_line_parts.empty()) {
		details = details.substr(0, details.length() -
			DETAIL_ITEM_SUFFIX_LENGTH);
	}

	Console::information() << (Formatter(DETAILS_MESSAGE) << code_line_parts
		.size() << details);
	Console::information() << "";
}
