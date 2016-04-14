#ifndef NULLPOINTERTOCOMMANDLINEARGUMENT_H
#define NULLPOINTERTOCOMMANDLINEARGUMENT_H

#include <stdexcept>

namespace thewizardplusplus {
namespace utils {
namespace exceptions {

class NullPointerToCommandLineArgument : public std::runtime_error {
public:
	static const std::string MESSAGE;

	NullPointerToCommandLineArgument(size_t number);
};

}
}
}
#endif
