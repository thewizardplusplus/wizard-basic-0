#ifndef GNUASSEMBLER_H
#define GNUASSEMBLER_H

#include "Assembler.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {

class GnuAssembler : public Assembler {
public:
	typedef std::map<std::string, std::string> FloatConstantMap;

	GnuAssembler(AssemblerModule* assembler_module);

protected:
	virtual void beforeAssemble(void);
	virtual void processAssemblerMnemonic(const AssemblerMnemonic&
		assembler_mnemonic);
	virtual void afterAssemble(void);

private:
	FloatConstantMap float_constants;

	std::string getFloatConstantName(const std::string& value);
	int getVariableShift(const std::string& identifier) const;
	void makeFunctionCall(const std::string& function_name);
};

}
}
#endif
