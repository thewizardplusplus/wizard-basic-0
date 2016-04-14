#include "OperatorList.h"

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::utils;

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
