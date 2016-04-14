#ifndef INVALIDFUNCTIONIDENTIFIER_H
#define INVALIDFUNCTIONIDENTIFIER_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {
namespace exceptions {

class InvalidFunctionIdentifier : public CompileException {
public:
	static const std::string MESSAGE;

	InvalidFunctionIdentifier(const std::string& identifier);
};

}
}
}
#endif
