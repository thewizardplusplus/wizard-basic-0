#include "EmptyLineDeleter.h"

using namespace thewizardplusplus::wizard_basic_0;

void EmptyLineDeleter::preprocess(CodeLines& code_lines) {
	CodeLines::iterator i = code_lines.begin();
	while (i != code_lines.end()) {
		if (i->second.empty()) {
			CodeLines::iterator next_i = i;
			next_i++;

			code_lines.erase(i);
			i = next_i;
		} else {
			++i;
		}
	}
}
