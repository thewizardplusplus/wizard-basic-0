#ifndef IFWITHOUTEND_H
#define IFWITHOUTEND_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
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
