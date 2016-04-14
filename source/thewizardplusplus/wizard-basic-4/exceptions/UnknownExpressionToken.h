#ifndef UNKNOWNEXPRESSIONTOKEN_H
#define UNKNOWNEXPRESSIONTOKEN_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {
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
