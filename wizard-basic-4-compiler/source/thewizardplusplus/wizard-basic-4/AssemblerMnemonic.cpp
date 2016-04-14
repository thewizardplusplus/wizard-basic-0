#include "AssemblerMnemonic.h"
#include "../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::utils;

const std::string AssemblerMnemonic::FORMAT_GENERAL = "%0%%1%";
const std::string AssemblerMnemonic::FORMAT_OPERAND = " %0%";

AssemblerMnemonic::AssemblerMnemonic(const std::string& mnemonic,
	const std::string& operand)
:
	mnemonic(mnemonic),
	operand(operand)
{}

AssemblerMnemonic::operator std::string(void) const {
	return toString();
}

std::string AssemblerMnemonic::getMnemonic(void) const {
	return mnemonic;
}

std::string AssemblerMnemonic::getOperand(void) const {
	return operand;
}

std::string AssemblerMnemonic::toString(void) const {
	std::string operand;
	if (!this->operand.empty()) {
		operand = Formatter(FORMAT_OPERAND).setArgument(this->operand);
	}

	return Formatter(FORMAT_GENERAL).setArgument(mnemonic).setArgument(operand);
}
