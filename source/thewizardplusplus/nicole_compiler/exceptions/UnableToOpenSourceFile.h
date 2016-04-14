#ifndef UNABLETOOPENSOURCEFILE_H
#define UNABLETOOPENSOURCEFILE_H

#include <stdexcept>

namespace thewizard {
namespace nicole_compiler {
namespace exceptions {

class UnableToOpenSourceFile : public std::runtime_error {
public:
	static const std::string MESSAGE;

	UnableToOpenSourceFile(const std::string& filname);
};

}
}
}
#endif
