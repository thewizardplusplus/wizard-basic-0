#ifndef UNKNOWNSTATEMENT_H
#define UNKNOWNSTATEMENT_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class MissedFunctionArgumentSeparatorOrOpeningBracket : public CompileException
{
public:
	static const std::string MESSAGE;

	MissedFunctionArgumentSeparatorOrOpeningBracket(void);
};

}
}
}
#endif
