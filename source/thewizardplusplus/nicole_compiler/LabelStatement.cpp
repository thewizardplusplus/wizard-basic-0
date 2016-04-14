#include "LabelStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "Compiler.h"
#include "AssemblerModule.h"

using namespace thewizardplusplus::nicole_compiler;
using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string LabelStatement::MARK = "label";

LabelStatement::LabelStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK)
{}

void LabelStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	std::string label = code_line_parts.front();
	getCompiler()->getAssemblerModule()->createLabel(label);
}
