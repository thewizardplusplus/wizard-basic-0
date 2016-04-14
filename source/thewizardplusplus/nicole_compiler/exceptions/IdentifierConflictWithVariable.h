#ifndef IDENTIFIERCONFLICTWITHVARIABLE_H
#define IDENTIFIERCONFLICTWITHVARIABLE_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
namespace exceptions {

class IdentifierConflictWithVariable : public CompileException {
public:
	static const std::string MESSAGE;

	IdentifierConflictWithVariable(const std::string& identifier);
};

}
}
}
#endif
