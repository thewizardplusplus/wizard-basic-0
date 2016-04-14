#ifndef CODELINES_H
#define CODELINES_H

#include <map>
#include <string>

namespace thewizard {
namespace nicole_compiler {

class CodeLines : public std::map<unsigned long int, std::string> {
public:
	static const std::string CODE_LINE_STRING_TEMPLATE;
	static const char        CODE_LINE_SEPARATOR;

	operator std::string(void) const;
	std::string toString(void) const;
};

}
}
#endif
