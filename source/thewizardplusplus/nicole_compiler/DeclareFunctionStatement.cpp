#include "DeclareFunctionStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "exceptions/InvalidFunctionIdentifier.h"
#include "Compiler.h"
#include "ExpressionCompiler.h"
#include "AssemblerModule.h"

using namespace thewizard::nicole_compiler;
using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string DeclareFunctionStatement::MARK =      "declare function";
const std::string DeclareFunctionStatement::SEPARATOR = "";

DeclareFunctionStatement::DeclareFunctionStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK, SEPARATOR)
{}

void DeclareFunctionStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	std::string identifier = code_line_parts.front();
	if (!ExpressionCompiler::isIdentifier(identifier)) {
		throw InvalidFunctionIdentifier(identifier);
	}
	getCompiler()->getAssemblerModule()->addFunctionIdentifier(identifier);
}
