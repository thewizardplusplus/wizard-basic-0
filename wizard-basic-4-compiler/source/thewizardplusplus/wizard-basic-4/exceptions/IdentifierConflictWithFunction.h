#ifndef IDENTIFIERCONFLICTWITHFUNCTION_H
#define IDENTIFIERCONFLICTWITHFUNCTION_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {
namespace exceptions {

class IdentifierConflictWithFunction : public CompileException {
public:
	static const std::string MESSAGE;

	IdentifierConflictWithFunction(const std::string& identifier);
};

}
}
}
#endif
