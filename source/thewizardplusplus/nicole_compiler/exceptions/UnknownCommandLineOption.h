#ifndef UNKNOWNCOMMANDLINEOPTION_H
#define UNKNOWNCOMMANDLINEOPTION_H

#include <stdexcept>

namespace thewizardplusplus {
namespace nicole_compiler {
namespace exceptions {

class UnknownCommandLineOption : public std::runtime_error {
public:
	static const std::string MESSAGE;

	UnknownCommandLineOption(const std::string& option);
};

}
}
}
#endif
