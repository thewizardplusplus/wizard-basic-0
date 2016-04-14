#include "StringUtils.h"
#include <algorithm>

using namespace thewizard::utils;

std::string StringUtils::trim(const std::string& string,
	unsigned int sides)
{
	std::string result = string;

	std::unary_negate<std::pointer_to_unary_function<int, int> > predicate =
		std::not1(std::ptr_fun<int, int>(std::isspace));
	if (sides & StringSide::LEFT) {
		std::string::iterator result_begin = result.begin();
		result.erase(result_begin, std::find_if(result_begin, result.end(),
			predicate));
	}
	if (sides & StringSide::RIGHT) {
		result.erase(std::find_if(result.rbegin(), result.rend(), predicate)
			.base(), result.end());
	}

	return result;
}

StringList StringUtils::split(const std::string& string,
	const std::string& separator, bool keep_empty_parts)
{
	StringList parts;

	size_t separator_length = separator.length();
	size_t previous_separator_index = 0;
	size_t separator_index = 0;
	while (true) {
		separator_index = string.find(separator, separator_index);
		if (separator_index != std::string::npos) {
			std::string part = string.substr(previous_separator_index,
				separator_index - previous_separator_index);
			if (keep_empty_parts || !part.empty()) {
				parts.push_back(part);
			}
		} else {
			std::string part = string.substr(previous_separator_index);
			if (keep_empty_parts || !part.empty()) {
				parts.push_back(part);
			}

			break;
		}

		separator_index += separator_length;
		previous_separator_index = separator_index;
	}

	return parts;
}

StringList StringUtils::tokenize(const std::string& string,
	const StringList& separators, bool return_separators)
{
	StringList tokens;
	tokens.push_back(string);

	StringList::const_iterator separators_iterator = separators.begin();
	for (; separators_iterator != separators.end(); ++separators_iterator) {
		StringList new_tokens;

		StringList::const_iterator tokens_iterator = tokens.begin();
		for (; tokens_iterator != tokens.end(); ++tokens_iterator) {
			StringList parts = split(*tokens_iterator, *separators_iterator,
				true);

			StringList::const_iterator parts_iterator = parts.begin();
			for (; parts_iterator != parts.end(); ++parts_iterator) {
				std::string part = trim(*parts_iterator);
				if (!part.empty()) {
					new_tokens.push_back(part);
				}
				if (return_separators && parts_iterator != --parts.end()) {
					new_tokens.push_back(*separators_iterator);
				}
			}
		}

		tokens = new_tokens;
	}

	return tokens;
}
