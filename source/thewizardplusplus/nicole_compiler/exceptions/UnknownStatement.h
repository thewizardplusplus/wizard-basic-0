#ifndef UNKNOWNSTATEMENT_H
#define UNKNOWNSTATEMENT_H

#include "CompileException.h"

namespace thewizardplusplus {
namespace nicole_compiler {
namespace exceptions {

class UnknownStatement : public CompileException {
public:
	static const std::string MESSAGE;

	UnknownStatement(void);
};

}
}
}
#endif
