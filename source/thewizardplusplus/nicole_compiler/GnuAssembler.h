#ifndef GNUASSEMBLER_H
#define GNUASSEMBLER_H

#include "Assembler.h"

namespace thewizard {
namespace nicole_compiler {

class GnuAssembler : public Assembler {
public:
	typedef std::map<std::string, std::string> FloatConstantMap;

	GnuAssembler(AssemblerModule* assembler_module);
	std::string getAssemblerCode(void) const;

protected:
	virtual void beforeAssemble(void);
	virtual void processAssemblerMnemonic(
		const AssemblerMnemonic& assembler_mnemonic);
	virtual void afterAssemble(void);

private:
	std::string      assembler_code;
	FloatConstantMap float_constants;

	std::string getFloatConstantName(std::string value);
	int getVariableShift(std::string identifier);
};

}
}
#endif
