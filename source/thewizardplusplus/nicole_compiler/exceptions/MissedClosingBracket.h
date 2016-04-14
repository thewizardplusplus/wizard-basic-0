#ifndef MISSEDCLOSINGBRACKET_H
#define MISSEDCLOSINGBRACKET_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace nicole_compiler {
namespace exceptions {

class MissedClosingBracket : public CompileException {
public:
	static const std::string MESSAGE;

	MissedClosingBracket(void);
};

}
}
}
#endif
