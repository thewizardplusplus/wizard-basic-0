#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include "StringSide.h"
#include "StringList.h"

namespace thewizard {
namespace utils {

class StringUtils {
public:
	static std::string trim(const std::string& string, unsigned int sides =
		StringSide::LEFT | StringSide::RIGHT);
	static StringList split(const std::string& string,
		const std::string& separator, bool keep_empty_parts = true);
	static StringList tokenize(const std::string& string,
		const StringList& separators, bool return_separators = false);
};

}
}
#endif
