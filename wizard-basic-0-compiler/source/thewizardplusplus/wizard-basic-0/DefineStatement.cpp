#include "DefineStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "ExpressionCompiler.h"
#include "exceptions/InvalidIdentifierFormat.h"
#include "exceptions/InvalidStringFormat.h"
#include "Compiler.h"
#include "AssemblerModule.h"

using namespace thewizardplusplus::wizard_basic_0;
using namespace thewizardplusplus::wizard_basic_0::exceptions;
using namespace thewizardplusplus::utils;

const std::string DefineStatement::MARK =      "define";
const std::string DefineStatement::SEPARATOR = "as";

DefineStatement::DefineStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK, SEPARATOR)
{}

void DefineStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	std::string identifier = code_line_parts.front();
	if (!ExpressionCompiler::isIdentifier(identifier)) {
		throw InvalidIdentifierFormat(identifier);
	}

	std::string string = code_line_parts.back();
	if (string.length() < 2 || string[0] != QUOTE_SYMBOL || string[
		string.length() - 1] != QUOTE_SYMBOL)
	{
		throw InvalidStringFormat();
	}

	getCompiler()->getAssemblerModule()->addStringConstant(identifier, string
		.substr(1, string.length() - 2));
}
