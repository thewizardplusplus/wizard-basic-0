#ifndef TESTSTATEMENT_H
#define TESTSTATEMENT_H

#include "StatementCompiler.h"

namespace thewizard {
namespace nicole_compiler {

class TestStatement : public StatementCompiler {
public:
	static const std::string       FIRST_MESSAGE;
	static const std::string       DETAIL_ITEM;
	static const unsigned long int DETAIL_ITEM_SUFFIX_LENGTH = 2;
	static const std::string       DETAILS_MESSAGE;

	TestStatement(Compiler* compiler, const std::string& mark = std::string(),
		const std::string& separator = std::string());
	virtual void compile(const utils::StringList& code_line_parts);
};

}
}
#endif
