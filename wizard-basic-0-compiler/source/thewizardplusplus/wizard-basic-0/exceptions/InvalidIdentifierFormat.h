#ifndef INVALIDIDENTIFIERFORMAT_H
#define INVALIDIDENTIFIERFORMAT_H

#include "CompileException.h"
#include <string>

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class InvalidIdentifierFormat : public CompileException {
public:
	static const std::string MESSAGE;

	InvalidIdentifierFormat(const std::string& identifier);
};

}
}
}
#endif
