#include "CommentDeleter.h"

using namespace thewizard::nicole_compiler;

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
			code_lines.erase(i++);
		} else {
			++i;
		}
	}
}
