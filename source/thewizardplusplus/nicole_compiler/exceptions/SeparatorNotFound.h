#ifndef SEPARATORNOTFOUND_H
#define SEPARATORNOTFOUND_H

#include "CompileException.h"

namespace thewizard {
namespace nicole_compiler {
namespace exceptions {

class SeparatorNotFound : public CompileException {
public:
	static const std::string MESSAGE;

	SeparatorNotFound(const std::string& mark, const std::string& separator);
};

}
}
}
#endif
