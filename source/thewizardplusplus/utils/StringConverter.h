#ifndef STRINGCONVERTER_H
#define STRINGCONVERTER_H

#include <string>
#include <sstream>

namespace thewizardplusplus {
namespace utils {

class StringConverter {
public:
	template<typename Type>
	static std::string convert(Type value);
	static std::string convert(const char* value);
	static std::string convert(const std::string& value);
};

template<typename Type>
std::string StringConverter::convert(Type value) {
	std::ostringstream out;
	out.operator<<(value);

	return out.str();
}

}
}
#endif
