#ifndef ASSEMBLINGORLINKINGEXCEPTION_H
#define ASSEMBLINGORLINKINGEXCEPTION_H

#include <stdexcept>
#include <string>

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class AssemblingOrLinkingException : public std::runtime_error {
public:
	static const std::string MESSAGE;

	AssemblingOrLinkingException(void);
};

}
}
}
#endif
