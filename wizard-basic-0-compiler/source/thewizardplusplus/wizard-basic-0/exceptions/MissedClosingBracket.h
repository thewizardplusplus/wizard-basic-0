#ifndef MISSEDCLOSINGBRACKET_H
#define MISSEDCLOSINGBRACKET_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {
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
