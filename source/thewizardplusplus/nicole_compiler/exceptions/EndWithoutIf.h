#ifndef ENDWITHOUTIF_H
#define ENDWITHOUTIF_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
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
