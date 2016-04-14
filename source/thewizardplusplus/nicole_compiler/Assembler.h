#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "AssemblerModule.h"

namespace thewizard {
namespace nicole_compiler {

class Assembler {
public:
	static const std::string INVALID_ARGUMENT_MESSAGE;

	Assembler(AssemblerModule* assembler_module);
	virtual ~Assembler(void);
	AssemblerModule* getAssemblerModule(void) const;
	void assemble(const std::string& output_filename = std::string());

protected:
	std::string output_filename;

	virtual void beforeAssemble(void);
	virtual void processAssemblerMnemonic(
		const AssemblerMnemonic& assembler_mnemonic) = 0;
	virtual void afterAssemble(void);

private:
	AssemblerModule* assembler_module;
};

}
}
#endif
