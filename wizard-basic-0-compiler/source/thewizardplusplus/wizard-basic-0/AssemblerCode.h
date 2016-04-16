#ifndef ASSEMBLERCODE_H
#define ASSEMBLERCODE_H

#include "AssemblerMnemonic.h"
#include <list>

namespace thewizardplusplus {
namespace wizard_basic_0 {

class AssemblerCode : public std::list<AssemblerMnemonic> {
public:
	static const std::string       MNEMONIC_SEPARATOR;
	static const unsigned long int MNEMONIC_SEPARATOR_LENGTH = 1;

	operator std::string(void) const;
	std::string toString(void) const;
};

}
}
#endif
