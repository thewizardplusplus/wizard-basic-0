#include "AssemblerMnemonic.h"

using namespace thewizard::nicole_compiler;

AssemblerMnemonic::AssemblerMnemonic(const std::string& mnemonic,
	const std::string& operand)
:
	mnemonic(mnemonic),
	operand(operand)
{}

std::string AssemblerMnemonic::getMnemonic(void) const {
	return mnemonic;
}

std::string AssemblerMnemonic::getOperand(void) const {
	return operand;
}
