#ifndef EXPRESSIONCOMPILER_H
#define EXPRESSIONCOMPILER_H

#include "OperatorList.h"
#include "../utils/StringList.h"

namespace thewizardplusplus {
namespace nicole_compiler {

class Compiler;

class ExpressionCompiler {
public:
	static const std::string INVALID_ARGUMENT_MESSAGE;
	static const std::string WHITESPACE;
	static const char        DOT_SYMBOL;
	static const char        UNDERSCORE_SYMBOL;

	static bool isNumber(const std::string& token);
	static bool isIdentifier(const std::string& token);

	ExpressionCompiler(Compiler* compiler, const OperatorList& operators,
		const std::string& opening_bracket, const std::string& closing_bracket,
		const std::string& function_argument_separator);
	void compile(const std::string& expression_code);

private:
	Compiler*                         compiler;
	OperatorList                      operators;
	utils::StringList                 token_separators;
	std::string                       opening_bracket;
	std::string                       closing_bracket;
	std::string                       function_argument_separator;

	bool isOperator(const std::string& token) const;
};

}
}
#endif
