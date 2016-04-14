#ifndef INVALIDSTRINGFORMAT_H
#define INVALIDSTRINGFORMAT_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
namespace exceptions {

class InvalidStringFormat : public CompileException {
public:
	static const std::string MESSAGE;

	InvalidStringFormat(void);
};

}
}
}
#endif
