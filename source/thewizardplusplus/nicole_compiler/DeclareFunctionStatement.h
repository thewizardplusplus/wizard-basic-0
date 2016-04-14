#ifndef DECLAREFUNCTIONSTATEMENT_H
#define DECLAREFUNCTIONSTATEMENT_H

#include "StatementCompiler.h"

namespace thewizardplusplus {
namespace nicole_compiler {

class DeclareFunctionStatement : public StatementCompiler {
public:
	static const std::string  MARK;
	static const unsigned int NUMBER_OF_CODE_LINE_PARTS = 1;

	DeclareFunctionStatement(Compiler* compiler);
	virtual void compile(const utils::StringList& code_line_parts);
};

}
}
#endif
