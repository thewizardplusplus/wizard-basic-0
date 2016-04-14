#include "EmptyLineDeleter.h"

using namespace thewizard::nicole_compiler;

void EmptyLineDeleter::preprocess(CodeLines& code_lines) {
	CodeLines::iterator i = code_lines.begin();
	while (i != code_lines.end()) {
		if (i->second.empty()) {
			code_lines.erase(i++);
		} else {
			++i;
		}
	}
}
