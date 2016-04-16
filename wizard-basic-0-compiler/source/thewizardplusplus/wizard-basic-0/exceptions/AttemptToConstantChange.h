#ifndef ATTEMPTTOCONSTANTCHANGE_H
#define ATTEMPTTOCONSTANTCHANGE_H

#include "CompileException.h"
#include <string>

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class AttemptToConstantChange : public CompileException {
public:
	static const std::string MESSAGE;

	AttemptToConstantChange(const std::string& identifier);
};

}
}
}
#endif
