#ifndef UNDEFINEDVARIABLE_H
#define UNDEFINEDVARIABLE_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace nicole_compiler {
namespace exceptions {

class UndefinedVariable : public CompileException {
public:
	static const std::string MESSAGE;

	UndefinedVariable(const std::string& identifier);
};

}
}
}
#endif
