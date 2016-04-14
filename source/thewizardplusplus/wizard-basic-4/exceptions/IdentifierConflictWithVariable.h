#ifndef IDENTIFIERCONFLICTWITHVARIABLE_H
#define IDENTIFIERCONFLICTWITHVARIABLE_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {
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
