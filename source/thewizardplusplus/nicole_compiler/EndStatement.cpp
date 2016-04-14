#include "EndStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "Compiler.h"
#include "AssemblerModule.h"

using namespace thewizardplusplus::nicole_compiler;
using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string EndStatement::MARK = "end";

EndStatement::EndStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK)
{}

void EndStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	getCompiler()->getAssemblerModule()->createLabelForConditionalJump();
}
