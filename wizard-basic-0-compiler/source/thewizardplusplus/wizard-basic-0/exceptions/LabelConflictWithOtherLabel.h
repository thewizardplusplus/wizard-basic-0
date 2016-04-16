#ifndef LABELCONFLICTWITHOTHERLABEL_H
#define LABELCONFLICTWITHOTHERLABEL_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class LabelConflictWithOtherLabel : public CompileException {
public:
	static const std::string MESSAGE;

	LabelConflictWithOtherLabel(const std::string& identifier);
};

}
}
}
#endif
