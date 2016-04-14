#ifndef INVALIDNUMBEROFCODELINEPARTS_H
#define INVALIDNUMBEROFCODELINEPARTS_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
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
