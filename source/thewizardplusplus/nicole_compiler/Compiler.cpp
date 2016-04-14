#include "Compiler.h"
#include "ExpressionCompiler.h"
#include "StatementCompiler.h"
#include "AssemblerModule.h"
#include "exceptions/UnknownStatement.h"
#include "../utils/StringUtils.h"
#include "exceptions/SeparatorNotFound.h"
#include <stdexcept>

using namespace thewizard::nicole_compiler;
using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string Compiler::INVALID_ARGUMENT_MESSAGE = "Unable to construct "
	"Compiler with null AssemblerModule pointer.";

Compiler::Compiler(AssemblerModule* assembler_module) :
	assembler_module(assembler_module),
	default_statement_compiler(NULL),
	expression_compiler(NULL)
{
	if (assembler_module == NULL) {
		throw std::invalid_argument(INVALID_ARGUMENT_MESSAGE);
	}
}

Compiler::~Compiler(void) {
	if (expression_compiler != NULL) {
		delete expression_compiler;
		expression_compiler = NULL;
	}

	if (default_statement_compiler != NULL) {
		delete default_statement_compiler;
		default_statement_compiler = NULL;
	}

	StatementCompilerList::const_iterator i = statement_compilers.begin();
	for (; i != statement_compilers.end(); ++i) {
		delete *i;
	}
}

AssemblerModule* Compiler::getAssemblerModule(void) const {
	return assembler_module;
}

void Compiler::addStatementCompiler(StatementCompiler* statement_compiler) {
	if (statement_compiler != NULL) {
		statement_compilers.push_back(statement_compiler);
	}
}

void Compiler::setDefaultStatementCompiler(
	StatementCompiler* statement_compiler)
{
	default_statement_compiler = statement_compiler;
}

ExpressionCompiler* Compiler::getExpressionCompiler(void) const {
	return expression_compiler;
}

void Compiler::setExpressionCompiler(ExpressionCompiler* expression_compiler) {
	this->expression_compiler = expression_compiler;
}

void Compiler::compile(const CodeLines& code_lines) {
	CodeLines::const_iterator i = code_lines.begin();
	for (; i != code_lines.end(); ++i) {
		std::string code_line = i->second;

		try {
			bool compiled = false;
			StatementCompilerList::const_iterator j = statement_compilers
				.begin();
			for (; j != statement_compilers.end(); ++j) {
				compiled = transmitCodeLineToStatementCompiler(code_line, *j);
				if (compiled) {
					break;
				}
			}

			if (!compiled) {
				if (default_statement_compiler != NULL) {
					compiled = transmitCodeLineToStatementCompiler(code_line,
						default_statement_compiler);
					if (!compiled) {
						throw UnknownStatement();
					}
				} else {
					throw UnknownStatement();
				}
			}
		} catch (CompileException& exception) {
			exception.setLineNumber(i->first);
			throw;
		}
	}

	try {
		assembler_module->checkForErrors();
	} catch (CompileException& exception) {
		unsigned long int maximal_line_number = 0;
		if (!code_lines.empty()) {
			maximal_line_number = code_lines.rbegin()->first;
		}

		exception.setLineNumber(maximal_line_number);
		throw;
	}
}

bool Compiler::transmitCodeLineToStatementCompiler(const std::string& code_line,
	StatementCompiler* statement_compiler)
{
	std::string mark = statement_compiler->getMark();
	size_t mark_length = mark.length();
	if (mark_length == 0 || code_line.substr(0, mark_length) == mark) {
		std::string truncated_code_line;
		if (mark_length != 0) {
			truncated_code_line = StringUtils::trim(code_line.substr(
				mark_length));
		} else {
			truncated_code_line = code_line;
		}

		StringList code_line_parts;
		std::string separator = statement_compiler->getSeparator();
		size_t separator_length = separator.length();
		if (separator_length != 0) {
			size_t separator_index = truncated_code_line.find(
				separator);
			if (separator_index != std::string::npos) {
				code_line_parts.push_back(StringUtils::trim(
					truncated_code_line.substr(0, separator_index)));
				code_line_parts.push_back(StringUtils::trim(
					truncated_code_line.substr(separator_index +
					separator_length)));
			} else {
				throw SeparatorNotFound(mark, separator);
			}
		} else {
			code_line_parts.push_back(truncated_code_line);
		}
		statement_compiler->compile(code_line_parts);

		return true;
	}

	return false;
}
