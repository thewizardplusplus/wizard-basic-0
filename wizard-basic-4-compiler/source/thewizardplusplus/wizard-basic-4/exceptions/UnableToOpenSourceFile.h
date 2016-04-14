#ifndef UNABLETOOPENSOURCEFILE_H
#define UNABLETOOPENSOURCEFILE_H

#include <stdexcept>

namespace thewizardplusplus {
namespace wizard_basic_4 {
namespace exceptions {

class UnableToOpenSourceFile : public std::runtime_error {
public:
	static const std::string MESSAGE;

	UnableToOpenSourceFile(const std::string& filename);
};

}
}
}
#endif
