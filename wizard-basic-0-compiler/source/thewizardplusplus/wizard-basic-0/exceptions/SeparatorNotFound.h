#ifndef SEPARATORNOTFOUND_H
#define SEPARATORNOTFOUND_H

#include "CompileException.h"
#include "../StatementCompiler.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class SeparatorNotFound : public CompileException {
public:
	static const std::string MESSAGE;

	SeparatorNotFound(StatementCompiler* statement_compiler);
};

}
}
}
#endif
