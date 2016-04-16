#include "LetStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "ExpressionCompiler.h"
#include "exceptions/InvalidIdentifierFormat.h"
#include "Compiler.h"
#include "ExpressionCompiler.h"
#include "AssemblerModule.h"

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::wizard_basic_4::exceptions;
using namespace thewizardplusplus::utils;

const std::string LetStatement::MARK =      "let";
const std::string LetStatement::SEPARATOR = "=";

LetStatement::LetStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK, SEPARATOR)
{}

void LetStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	std::string identifier = code_line_parts.front();
	if (!ExpressionCompiler::isIdentifier(identifier)) {
		throw InvalidIdentifierFormat(identifier);
	}

	std::string expression = code_line_parts.back();
	getCompiler()->getExpressionCompiler()->compile(expression);

	AssemblerModule* assembler_module = getCompiler()->getAssemblerModule();
	if (!assembler_module->isDefinedVariable(identifier)) {
		assembler_module->addVariableIdentifier(identifier);
	}
	assembler_module->createPopToVariable(identifier);
}
