#ifndef LABELCONFLICTWITHCONDITIONALJUMPS_H
#define LABELCONFLICTWITHCONDITIONALJUMPS_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {
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
