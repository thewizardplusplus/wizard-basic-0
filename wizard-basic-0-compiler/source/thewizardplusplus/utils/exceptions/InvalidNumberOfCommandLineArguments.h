#ifndef INVALIDCOMMANDLINEARGUMENTS_H
#define INVALIDCOMMANDLINEARGUMENTS_H

#include "../CommandLineArguments.h"
#include <stdexcept>

namespace thewizardplusplus {
namespace utils {
namespace exceptions {

class InvalidNumberOfCommandLineArguments : public std::runtime_error {
public:
	static const std::string MESSAGE_GENERAL;
	static const std::string MESSAGE_FOR_UNKNOWN_ERROR;
	static const std::string MESSAGE_FOR_OPEN_INTERVAL;
	static const std::string MESSAGE_FOR_CLOSED_INTERVAL;
	static const std::string MESSAGE_FOR_ONE_ARGUMENT;
	static const std::string MESSAGE_FOR_SPECIFIC_NUMBER;

	InvalidNumberOfCommandLineArguments(size_t number_of_arguments,
		size_t limit_of_number_of_arguments1,
		size_t limit_of_number_of_arguments2);

private:
	std::string constructMessage(size_t number_of_arguments,
		size_t limit_of_number_of_arguments1,
		size_t limit_of_number_of_arguments2) const;
};

}
}
}
#endif
