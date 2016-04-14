#ifndef ENDSTATEMENT_H
#define ENDSTATEMENT_H

#include "StatementCompiler.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {

class EndStatement : public StatementCompiler {
public:
	static const std::string  MARK;
	static const unsigned int NUMBER_OF_CODE_LINE_PARTS = 1;

	EndStatement(Compiler* compiler);
	virtual void compile(const utils::StringList& code_line_parts);
};

}
}
#endif
