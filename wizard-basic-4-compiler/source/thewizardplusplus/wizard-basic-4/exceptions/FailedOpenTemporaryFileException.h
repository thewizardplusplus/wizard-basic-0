#ifndef FAILEDOPENTEMPORARYFILEEXCEPTION_H
#define FAILEDOPENTEMPORARYFILEEXCEPTION_H

#include <stdexcept>
#include <string>

namespace thewizardplusplus {
namespace wizard_basic_4 {
namespace exceptions {

class FailedOpenTemporaryFileException : public std::runtime_error {
public:
	static const std::string MESSAGE;

	FailedOpenTemporaryFileException(const std::string& filename);
};

}
}
}
#endif
