#ifndef FORMATTER_H
#define FORMATTER_H

#include "FormatterTextAlign.h"
#include "StringConverter.h"
#include <string>

namespace thewizard {
namespace utils {

class Formatter {
public:
	static const char ESCAPE_CHAR =       '%';
	static const char DEFAULT_FILL_CHAR = ' ';

	Formatter(const std::string& template_string);
	template<typename Type>
	Formatter& operator<<(Type argument);
	operator const char*(void) const;
	operator std::string(void) const;
	template<typename Type>
	Formatter& setArgument(Type argument, size_t field_width = 0,
		FormatterTextAlign::Types text_align = FormatterTextAlign::RIGHT,
		char fill_char = DEFAULT_FILL_CHAR);
	Formatter& setArgument(const char* argument, size_t field_width = 0,
		FormatterTextAlign::Types text_align = FormatterTextAlign::RIGHT,
		char fill_char = DEFAULT_FILL_CHAR);
	Formatter& setArgument(std::string argument, size_t field_width = 0,
		FormatterTextAlign::Types text_align = FormatterTextAlign::RIGHT,
		char fill_char = DEFAULT_FILL_CHAR);
	Formatter& skipArgument(void);
	std::string toString(void) const;

private:
	std::string template_string;
	int         current_index;
};

template<typename Type>
Formatter& Formatter::operator<<(Type argument) {
	return setArgument(argument);
}

template<typename Type>
Formatter& Formatter::setArgument(Type argument, size_t field_width,
	FormatterTextAlign::Types text_align, char fill_char)
{
	setArgument(StringConverter::convert(argument).toString(), field_width,
		text_align, fill_char);
	return *this;
}

}
}
#endif
