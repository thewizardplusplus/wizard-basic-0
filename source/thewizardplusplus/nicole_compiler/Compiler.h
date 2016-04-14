#ifndef COMPILER_H
#define COMPILER_H

#include "CodeLines.h"
#include <list>

namespace thewizard {
namespace nicole_compiler {

class AssemblerModule;
class StatementCompiler;
class ExpressionCompiler;

class Compiler {
public:
	typedef std::list<StatementCompiler*> StatementCompilerList;

	static const std::string INVALID_ARGUMENT_MESSAGE;

	Compiler(AssemblerModule* assembler_module);
	~Compiler(void);
	AssemblerModule* getAssemblerModule(void) const;
	void addStatementCompiler(StatementCompiler* statement_compiler);
	void setDefaultStatementCompiler(StatementCompiler* statement_compiler);
	ExpressionCompiler* getExpressionCompiler(void) const;
	void setExpressionCompiler(ExpressionCompiler* expression_compiler);
	void compile(const CodeLines& code_lines);

private:
	AssemblerModule*      assembler_module;
	StatementCompilerList statement_compilers;
	StatementCompiler*    default_statement_compiler;
	ExpressionCompiler*   expression_compiler;

	bool transmitCodeLineToStatementCompiler(const std::string& code_line,
		StatementCompiler* statement_compiler);
};

}
}
#endif
