#ifndef NULLPOINTERTOARRAYOFCOMMANDLINEARGUMENTS_H
#define NULLPOINTERTOARRAYOFCOMMANDLINEARGUMENTS_H

#include <stdexcept>

namespace thewizardplusplus {
namespace utils {
namespace exceptions {

class NullPointerToArrayOfCommandLineArguments : public std::runtime_error {
public:
	static const std::string MESSAGE;

	NullPointerToArrayOfCommandLineArguments(void);
};

}
}
}
#endif
