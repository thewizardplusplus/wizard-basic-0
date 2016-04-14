#ifndef ASSEMBLERMNEMONIC_H
#define ASSEMBLERMNEMONIC_H

#include <string>

namespace thewizard {
namespace nicole_compiler {

class AssemblerMnemonic {
public:
	AssemblerMnemonic(const std::string& mnemonic, const std::string& operand =
		std::string());
	std::string getMnemonic(void) const;
	std::string getOperand(void) const;

private:
	std::string mnemonic;
	std::string operand;
};

}
}
#endif
