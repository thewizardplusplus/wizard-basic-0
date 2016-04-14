#ifndef LABELSTATEMENT_H
#define LABELSTATEMENT_H

#include "StatementCompiler.h"

namespace thewizardplusplus {
namespace nicole_compiler {

class LabelStatement : public StatementCompiler {
public:
	static const std::string  MARK;
	static const unsigned int NUMBER_OF_CODE_LINE_PARTS = 1;

	LabelStatement(Compiler* compiler);
	virtual void compile(const utils::StringList& code_line_parts);
};

}
}
#endif
