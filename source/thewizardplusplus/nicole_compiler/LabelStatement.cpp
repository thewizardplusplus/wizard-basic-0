#include "LabelStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "Compiler.h"
#include "AssemblerModule.h"

using namespace thewizard::nicole_compiler;
using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string LabelStatement::MARK =      "label";
const std::string LabelStatement::SEPARATOR = "";

LabelStatement::LabelStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK, SEPARATOR)
{}

void LabelStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	std::string label = code_line_parts.front();
	getCompiler()->getAssemblerModule()->createLabel(label);
}
