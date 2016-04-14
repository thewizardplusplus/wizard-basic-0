#ifndef DEFINESTATEMENT_H
#define DEFINESTATEMENT_H

#include "StatementCompiler.h"

namespace thewizard {
namespace nicole_compiler {

class DefineStatement : public StatementCompiler {
public:
	static const std::string  MARK;
	static const std::string  SEPARATOR;
	static const unsigned int NUMBER_OF_CODE_LINE_PARTS = 2;
	static const char         QUOTE_SYMBOL              = '\"';

	DefineStatement(Compiler* compiler);
	virtual void compile(const utils::StringList& code_line_parts);
};

}
}
#endif
