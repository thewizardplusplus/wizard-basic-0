#ifndef COMMENTDELETER_H
#define COMMENTDELETER_H

#include "Preprocessor.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {

class CommentDeleter : public Preprocessor {
public:
	CommentDeleter(const std::string& comment_mark);
	virtual void preprocess(CodeLines& code_lines);

private:
	std::string comment_mark;
	size_t      comment_mark_length;
};

}
}
#endif
