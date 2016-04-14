#ifndef LETSTATEMENT_H
#define LETSTATEMENT_H

#include "StatementCompiler.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {

class LetStatement : public StatementCompiler {
public:
	static const std::string  MARK;
	static const std::string  SEPARATOR;
	static const unsigned int NUMBER_OF_CODE_LINE_PARTS = 2;

	LetStatement(Compiler* compiler);
	virtual void compile(const utils::StringList& code_line_parts);
};

}
}
#endif
