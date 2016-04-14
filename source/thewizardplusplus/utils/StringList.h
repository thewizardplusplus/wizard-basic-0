#ifndef STRINGLIST_H
#define STRINGLIST_H

#include <list>
#include <string>

namespace thewizard {
namespace utils {

class StringList : public std::list<std::string> {
public:
	static const std::string       ITEM;
	static const unsigned long int ITEM_SUFFIX_LENGTH = 2;
	static const std::string       MESSAGE;

	operator std::string(void) const;
	std::string join(const std::string& separator);
	std::string toString(void) const;
};

}
}
#endif
