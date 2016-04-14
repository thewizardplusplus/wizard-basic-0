#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "AssemblerModule.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {

class Assembler {
public:
	static const std::string INVALID_ARGUMENT_MESSAGE;

	Assembler(AssemblerModule* assembler_module);
	virtual ~Assembler(void);
	AssemblerModule* getAssemblerModule(void) const;
	std::string getAssemblerCode(void) const;
	void assemble(void);

protected:
	std::string assembler_code;

	virtual void beforeAssemble(void);
	virtual void processAssemblerMnemonic(const AssemblerMnemonic&
		assembler_mnemonic) = 0;
	virtual void afterAssemble(void);

private:
	AssemblerModule* assembler_module;
};

}
}
#endif
