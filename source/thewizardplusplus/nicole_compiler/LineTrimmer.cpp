#include "LineTrimmer.h"
#include "../utils/StringUtils.h"

using namespace thewizard::nicole_compiler;
using namespace thewizard::utils;

void LineTrimmer::preprocess(CodeLines& code_lines) {
	CodeLines::iterator i = code_lines.begin();
	for (; i != code_lines.end(); ++i) {
		i->second = StringUtils::trim(i->second);
	}
}
