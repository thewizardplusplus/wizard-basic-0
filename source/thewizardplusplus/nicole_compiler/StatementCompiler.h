#ifndef STATEMENTCOMPILER_H
#define STATEMENTCOMPILER_H

#include "../utils/StringUtils.h"

namespace thewizardplusplus {
namespace nicole_compiler {

class Compiler;

class StatementCompiler {
public:
	static const std::string INVALID_ARGUMENT_MESSAGE;

	StatementCompiler(Compiler* compiler, const std::string& mark,
		const std::string& separator = std::string());
	virtual ~StatementCompiler(void);
	Compiler* getCompiler(void) const;
	std::string getMark(void) const;
	std::string getSeparator(void) const;
	virtual void compile(const utils::StringList& code_line_parts) = 0;

private:
	Compiler*   compiler;
	std::string mark;
	std::string separator;
};

}
}
#endif
