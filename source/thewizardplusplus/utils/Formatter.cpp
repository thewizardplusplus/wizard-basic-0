#include "Formatter.h"
#include "Console.h"
#include <sstream>

using namespace thewizardplusplus::utils;

Formatter::Formatter(const std::string& template_string) :
	template_string(template_string),
	current_index(0)
{}

Formatter::operator std::string(void) const {
	return toString();
}

Formatter& Formatter::setArgument(const char* argument, size_t field_width,
	FormatterTextAlign::Types text_align, char fill_char)
{
	setArgument(std::string(argument), field_width, text_align, fill_char);
	return *this;
}

Formatter& Formatter::setArgument(std::string argument, size_t field_width,
	FormatterTextAlign::Types text_align, char fill_char)
{
	std::ostringstream out;
	out << ESCAPE_CHAR << current_index << ESCAPE_CHAR;
	std::string mark = out.str();
	current_index++;

	size_t index = template_string.find(mark);
	if (index != std::string::npos) {
		std::string extended_argument = argument;

		size_t argument_length = extended_argument.length();
		if (argument_length < field_width) {
			size_t additional_space = field_width - argument_length;
			switch (text_align) {
			case FormatterTextAlign::LEFT:
				extended_argument.append(additional_space, fill_char);
				break;
			case FormatterTextAlign::CENTER_AND_LEFT: {
				size_t half_additional_space = additional_space / 2;
				extended_argument.insert(0, half_additional_space, fill_char);
				extended_argument.append(additional_space -
					half_additional_space, fill_char);
				break;
			}
			case FormatterTextAlign::CENTER_AND_RIGHT: {
				size_t half_additional_space = additional_space / 2;
				extended_argument.insert(0, additional_space -
					half_additional_space, fill_char);
				extended_argument.append(half_additional_space, fill_char);
				break;
			}
			case FormatterTextAlign::RIGHT:
			default:
				extended_argument.insert(0, additional_space, fill_char);
				break;
			}
		}

		template_string.replace(index, mark.length(), extended_argument);
	}

	return *this;
}

Formatter& Formatter::skipArgument(void) {
	current_index++;
	return *this;
}

std::string Formatter::toString(void) const {
	return template_string;
}
