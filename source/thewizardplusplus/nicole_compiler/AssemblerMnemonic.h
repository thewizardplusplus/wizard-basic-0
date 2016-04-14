#ifndef ASSEMBLERMNEMONIC_H
#define ASSEMBLERMNEMONIC_H

#include <string>

namespace thewizardplusplus {
namespace nicole_compiler {

class AssemblerMnemonic {
public:
	static const std::string FORMAT_GENERAL;
	static const std::string FORMAT_OPERAND;

	AssemblerMnemonic(const std::string& mnemonic, const std::string& operand =
		std::string());
	operator std::string(void) const;
	std::string getMnemonic(void) const;
	std::string getOperand(void) const;
	std::string toString(void) const;

private:
	std::string mnemonic;
	std::string operand;
};

}
}
#endif
