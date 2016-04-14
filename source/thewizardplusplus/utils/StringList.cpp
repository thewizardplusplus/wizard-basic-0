#include "StringList.h"
#include "Formatter.h"

using namespace thewizard::utils;

const std::string StringList::ITEM    = "\"%0%\", ";
const std::string StringList::MESSAGE = "StringList(%0%)";

StringList::operator std::string(void) const {
	return toString();
}

std::string StringList::join(const std::string& separator) {
	std::string result;

	const_iterator i = begin();
	for (; i != end(); ++i) {
		result += *i + separator;
	}
	if (!empty()) {
		result = result.substr(0, result.length() - separator.length());
	}

	return result;
}

std::string StringList::toString(void) const {
	std::string items;
	const_iterator i = begin();
	for (; i != end(); ++i) {
		items += Formatter(ITEM).setArgument(*i).toString();
	}
	if (!empty()) {
		items = items.substr(0, items.length() - ITEM_SUFFIX_LENGTH);
	}

	return Formatter(MESSAGE) << items;
}
