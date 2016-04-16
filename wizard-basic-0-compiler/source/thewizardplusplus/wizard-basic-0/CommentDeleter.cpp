#include "CommentDeleter.h"
#include <cctype>

using namespace thewizardplusplus::wizard_basic_0;

CommentDeleter::CommentDeleter(const std::string& comment_mark) :
	comment_mark(comment_mark),
	comment_mark_length(0)
{
	comment_mark_length = comment_mark.length();
}

void CommentDeleter::preprocess(CodeLines& code_lines) {
	CodeLines::iterator i = code_lines.begin();
	while (i != code_lines.end()) {
		std::string code_line = i->second;
		if ((code_line.length() > comment_mark_length && code_line.substr(0,
			comment_mark_length) == comment_mark && std::isspace(code_line[
			comment_mark_length])) || code_line == comment_mark)
		{
			CodeLines::iterator next_i = i;
			next_i++;

			code_lines.erase(i);
			i = next_i;
		} else {
			++i;
		}
	}
}
