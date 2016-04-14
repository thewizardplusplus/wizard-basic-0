#include "AssemblerCode.h"

using namespace thewizardplusplus::wizard_basic_4;

const std::string AssemblerCode::MNEMONIC_SEPARATOR = "\n";

AssemblerCode::operator std::string(void) const {
	return toString();
}

std::string AssemblerCode::toString(void) const {
	std::string result;
	const_iterator i = begin();
	for (; i != end(); ++i) {
		result += (*i).toString() + MNEMONIC_SEPARATOR;
	}
	if (!empty()) {
		result = result.substr(0, result.length() - MNEMONIC_SEPARATOR_LENGTH);
	}

	return result;
}
