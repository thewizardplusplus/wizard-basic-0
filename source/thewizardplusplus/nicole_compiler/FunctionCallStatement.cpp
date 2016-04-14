#include "FunctionCallStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "Compiler.h"
#include "ExpressionCompiler.h"

using namespace thewizard::nicole_compiler;
using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string FunctionCallStatement::MARK =      "";
const std::string FunctionCallStatement::SEPARATOR = "";

FunctionCallStatement::FunctionCallStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK, SEPARATOR)
{}

void FunctionCallStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	std::string expression = code_line_parts.front();

	ExpressionCompiler* expression_compiler = getCompiler()
		->getExpressionCompiler();
	expression_compiler->compile(expression);
}
