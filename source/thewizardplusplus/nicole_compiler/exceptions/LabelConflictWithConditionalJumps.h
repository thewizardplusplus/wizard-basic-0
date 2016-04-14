#ifndef LABELCONFLICTWITHCONDITIONALJUMPS_H
#define LABELCONFLICTWITHCONDITIONALJUMPS_H

#include "CompileException.h"

namespace thewizardplusplus {
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
