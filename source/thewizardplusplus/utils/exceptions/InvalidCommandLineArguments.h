#ifndef INVALIDCOMMANDLINEARGUMENTS_H
#define INVALIDCOMMANDLINEARGUMENTS_H

#include <stdexcept>

namespace thewizard {
namespace utils {
namespace exceptions {

class InvalidCommandLineArguments : public std::runtime_error {
public:
	static const std::string MESSAGE;

	InvalidCommandLineArguments(void);
};

}
}
}
#endif
