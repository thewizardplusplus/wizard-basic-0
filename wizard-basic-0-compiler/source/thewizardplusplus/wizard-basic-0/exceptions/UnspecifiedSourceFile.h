#ifndef UNSPECIFIEDSOURCEFILE_H
#define UNSPECIFIEDSOURCEFILE_H

#include <stdexcept>
#include <string>

namespace thewizardplusplus {
namespace wizard_basic_0 {
namespace exceptions {

class UnspecifiedSourceFile : public std::runtime_error {
public:
	static const std::string MESSAGE;

	UnspecifiedSourceFile(void);
};

}
}
}
#endif
