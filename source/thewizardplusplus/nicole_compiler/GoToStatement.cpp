#include "GoToStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "Compiler.h"
#include "ExpressionCompiler.h"
#include "AssemblerModule.h"

using namespace thewizardplusplus::nicole_compiler;
using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string GoToStatement::MARK = "go to";

GoToStatement::GoToStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK)
{}

void GoToStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	std::string expression = code_line_parts.front();
	getCompiler()->getExpressionCompiler()->compile(expression);
	getCompiler()->getAssemblerModule()->createJump();
}
