#include "LineTrimmer.h"
#include "../utils/StringUtils.h"

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::utils;

void LineTrimmer::preprocess(CodeLines& code_lines) {
	CodeLines::iterator i = code_lines.begin();
	for (; i != code_lines.end(); ++i) {
		i->second = StringUtils::trim(i->second);
	}
}
