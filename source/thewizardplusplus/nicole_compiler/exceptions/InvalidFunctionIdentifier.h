#ifndef INVALIDFUNCTIONIDENTIFIER_H
#define INVALIDFUNCTIONIDENTIFIER_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
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
