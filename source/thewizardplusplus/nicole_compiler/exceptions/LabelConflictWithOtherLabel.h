#ifndef LABELCONFLICTWITHOTHERLABEL_H
#define LABELCONFLICTWITHOTHERLABEL_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
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
