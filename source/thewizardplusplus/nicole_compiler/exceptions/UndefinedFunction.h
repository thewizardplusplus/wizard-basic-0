#ifndef UNDEFINEDFUNCTION_H
#define UNDEFINEDFUNCTION_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace nicole_compiler {
namespace exceptions {

class UndefinedFunction : public CompileException {
public:
	static const std::string MESSAGE;

	UndefinedFunction(const std::string& identifier);
};

}
}
}
#endif
