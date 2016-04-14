#include "CodeLines.h"
#include "../utils/StringConverter.h"
#include "../utils/Formatter.h"

using namespace thewizard::nicole_compiler;
using namespace thewizard::utils;

const std::string CodeLines::CODE_LINE_STRING_TEMPLATE = "%0% %1%";
const char        CodeLines::CODE_LINE_SEPARATOR =       '\n';

CodeLines::operator std::string(void) const {
	return toString();
}

std::string CodeLines::toString(void) const {
	unsigned long int maximal_line_number = 0;
	if (!empty()) {
		maximal_line_number = rbegin()->first;
	}
	size_t maximal_line_number_width = StringConverter::convert(
		maximal_line_number).toString().length();

	std::string result;
	const_iterator i = begin();
	for (; i != end(); ++i) {
		result += Formatter(CODE_LINE_STRING_TEMPLATE).setArgument(i->first,
			maximal_line_number_width).setArgument(i->second).toString() +
			CODE_LINE_SEPARATOR;
	}
	if (!empty()) {
		result = result.substr(0, result.length() - 1);
	}

	return result;
}
