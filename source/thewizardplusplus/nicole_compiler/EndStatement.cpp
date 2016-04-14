#include "EndStatement.h"
#include "exceptions/InvalidNumberOfCodeLineParts.h"
#include "Compiler.h"
#include "AssemblerModule.h"

using namespace thewizard::nicole_compiler;
using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string EndStatement::MARK =      "end";
const std::string EndStatement::SEPARATOR = "";

EndStatement::EndStatement(Compiler* compiler) :
	StatementCompiler(compiler, MARK, SEPARATOR)
{}

void EndStatement::compile(const StringList& code_line_parts) {
	if (code_line_parts.size() != NUMBER_OF_CODE_LINE_PARTS) {
		throw InvalidNumberOfCodeLineParts();
	}

	getCompiler()->getAssemblerModule()->createLabelForConditionalJump();
}
