#ifndef LABELCONFLICTWITHCONDITIONALJUMPS_H
#define LABELCONFLICTWITHCONDITIONALJUMPS_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
namespace exceptions {

class LabelConflictWithConditionalJumps : public CompileException {
public:
	static const std::string MESSAGE;

	LabelConflictWithConditionalJumps(void);
};

}
}
}
#endif
