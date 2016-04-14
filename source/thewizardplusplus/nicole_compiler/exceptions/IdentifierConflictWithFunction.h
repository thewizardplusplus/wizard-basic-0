#ifndef IDENTIFIERCONFLICTWITHFUNCTION_H
#define IDENTIFIERCONFLICTWITHFUNCTION_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
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
