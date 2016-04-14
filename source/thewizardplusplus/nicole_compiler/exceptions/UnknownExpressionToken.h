#ifndef UNKNOWNEXPRESSIONTOKEN_H
#define UNKNOWNEXPRESSIONTOKEN_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace nicole_compiler {
namespace exceptions {

class UnknownExpressionToken : public CompileException {
public:
	static const std::string MESSAGE;

	UnknownExpressionToken(const std::string& token);
};

}
}
}
#endif
