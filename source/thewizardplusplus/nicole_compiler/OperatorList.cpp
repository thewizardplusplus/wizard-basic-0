#include "OperatorList.h"

using namespace thewizard::nicole_compiler;
using namespace thewizard::utils;

StringList OperatorList::getOperatorTokens(void) const {
	StringList tokens;

	const_iterator i = begin();
	for (; i != end(); ++i) {
		tokens.push_back((*i).getToken());
	}

	return tokens;
}

Operator OperatorList::getOperatorByToken(const std::string& token) const {
	const_iterator i = begin();
	for (; i != end(); ++i) {
		Operator current_operator = *i;
		if (current_operator.getToken() == token) {
			return current_operator;
		}
	}

	return Operator();
}
