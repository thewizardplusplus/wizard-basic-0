#ifndef UNKNOWNSTATEMENT_H
#define UNKNOWNSTATEMENT_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
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
