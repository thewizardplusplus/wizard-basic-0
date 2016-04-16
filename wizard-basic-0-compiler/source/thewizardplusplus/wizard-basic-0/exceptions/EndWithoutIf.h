#ifndef ENDWITHOUTIF_H
#define ENDWITHOUTIF_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class EndWithoutIf : public CompileException {
public:
	static const std::string MESSAGE;

	EndWithoutIf(void);
};

}
}
}
#endif
