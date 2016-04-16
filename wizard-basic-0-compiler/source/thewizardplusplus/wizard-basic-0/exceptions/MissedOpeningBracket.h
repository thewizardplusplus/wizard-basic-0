#ifndef MISSEDOPENINGBRACKET_H
#define MISSEDOPENINGBRACKET_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class MissedOpeningBracket : public CompileException {
public:
	static const std::string MESSAGE;

	MissedOpeningBracket(void);
};

}
}
}
#endif
