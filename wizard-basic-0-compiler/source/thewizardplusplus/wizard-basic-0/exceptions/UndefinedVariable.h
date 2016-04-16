#ifndef UNDEFINEDVARIABLE_H
#define UNDEFINEDVARIABLE_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {
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
