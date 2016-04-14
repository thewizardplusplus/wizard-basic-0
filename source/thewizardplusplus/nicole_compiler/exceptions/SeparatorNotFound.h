#ifndef SEPARATORNOTFOUND_H
#define SEPARATORNOTFOUND_H

#include "CompileException.h"
#include "../StatementCompiler.h"

namespace thewizardplusplus {
namespace nicole_compiler {
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
