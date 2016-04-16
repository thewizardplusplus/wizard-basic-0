#ifndef INVALIDNUMBEROFCODELINEPARTS_H
#define INVALIDNUMBEROFCODELINEPARTS_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class InvalidNumberOfCodeLineParts : public CompileException {
public:
	static const std::string MESSAGE;

	InvalidNumberOfCodeLineParts(void);
};

}
}
}
#endif
