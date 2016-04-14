#include "LineTrimmer.h"
#include "../utils/StringUtils.h"

using namespace thewizardplusplus::nicole_compiler;
using namespace thewizardplusplus::utils;

void LineTrimmer::preprocess(CodeLines& code_lines) {
	CodeLines::iterator i = code_lines.begin();
	for (; i != code_lines.end(); ++i) {
		i->second = StringUtils::trim(i->second);
	}
}
