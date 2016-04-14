#ifndef CODELINES_H
#define CODELINES_H

#include <map>
#include <string>

namespace thewizardplusplus {
namespace wizard_basic_4 {

class CodeLines : public std::map<unsigned long int, std::string> {
public:
	static const std::string       CODE_LINE_STRING_TEMPLATE;
	static const std::string       CODE_LINE_SEPARATOR;
	static const unsigned long int CODE_LINE_SEPARATOR_LENGTH = 1;

	operator std::string(void) const;
	std::string toString(void) const;
};

}
}
#endif
