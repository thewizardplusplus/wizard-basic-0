#ifndef MISSEDOPENINGBRACKET_H
#define MISSEDOPENINGBRACKET_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
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
