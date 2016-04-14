#ifndef IFWITHOUTEND_H
#define IFWITHOUTEND_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {
namespace exceptions {

class IfWithoutEnd : public CompileException {
public:
	static const std::string MESSAGE;

	IfWithoutEnd(void);
};

}
}
}
#endif
