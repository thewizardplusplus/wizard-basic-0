#ifndef FUNCTIONCALLSTATEMENT_H
#define FUNCTIONCALLSTATEMENT_H

#include "StatementCompiler.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {

class FunctionCallStatement : public StatementCompiler {
public:
	static const std::string  MARK;
	static const std::string  SEPARATOR;
	static const unsigned int NUMBER_OF_CODE_LINE_PARTS = 1;

	FunctionCallStatement(Compiler* compiler);
	virtual void compile(const utils::StringList& code_line_parts);
};

}
}
#endif
