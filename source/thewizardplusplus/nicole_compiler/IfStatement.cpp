#include "IfStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "Compiler.h"
#include "ExpressionCompiler.h"
#include "AssemblerModule.h"

using namespace thewizard::nicole_compiler;
using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string IfStatement::MARK =      "if";
const std::string IfStatement::SEPARATOR = "then";

IfStatement::IfStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK, SEPARATOR)
{}

void IfStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	std::string expression = code_line_parts.front();
	getCompiler()->getExpressionCompiler()->compile(expression);
	getCompiler()->getAssemblerModule()->createConditionalJump();
}
