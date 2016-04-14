#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "AssemblerModule.h"

namespace thewizardplusplus {
namespace nicole_compiler {

class Assembler {
public:
	static const std::string INVALID_ARGUMENT_MESSAGE;

	Assembler(AssemblerModule* assembler_module);
	virtual ~Assembler(void);
	AssemblerModule* getAssemblerModule(void) const;
	std::string getOutputFilename(void) const;
	void assemble(const std::string& output_filename);

protected:
	virtual void beforeAssemble(void);
	virtual void processAssemblerMnemonic(
		const AssemblerMnemonic& assembler_mnemonic) = 0;
	virtual void afterAssemble(void);

private:
	AssemblerModule* assembler_module;
	std::string      output_filename;
};

}
}
#endif
