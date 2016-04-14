#ifndef ASSEMBLERMODULE_H
#define ASSEMBLERMODULE_H

#include "AssemblerCode.h"
#include "Operator.h"
#include "../utils/StringList.h"
#include <map>

namespace thewizardplusplus {
namespace nicole_compiler {

class AssemblerModule {
public:
	typedef std::map<std::string, std::string> StringConstantMap;

	static const std::string PUSH_NUMBER_MNEMONIC_NAME;
	static const std::string PUSH_VARIABLE_MNEMONIC_NAME;
	static const std::string POP_VARIABLE_MNEMONIC_NAME;
	static const std::string DO_MNEMONIC_NAME;
	static const std::string CALL_MNEMONIC_NAME;
	static const std::string LABEL_MNEMONIC_NAME;
	static const std::string JUMP_MNEMONIC_NAME;
	static const std::string JUMP_IF_ZERO_MNEMONIC_NAME;
	static const std::string CONDITIONAL_JUMP_LABEL_FORMAT;
	static const std::string CONDITIONAL_JUMP_BASE_LABEL;
	static const int         DEFAULT_LAST_CONDITIONAL_JUMP_ID = -1;

	AssemblerModule(void);
	AssemblerCode getAssemblerCode(void) const;
	StringConstantMap getDefinedStringConstants(void) const;
	bool isDefinedVariable(const std::string& identifier) const;
	utils::StringList getDefinedVariables(void) const;
	bool isDefinedFunction(const std::string& identifier) const;
	bool isDefinedLabel(const std::string& label) const;
	void addStringConstant(const std::string& identifier,
		const std::string& value);
	void addVariableIdentifier(const std::string& identifier);
	void addFunctionIdentifier(const std::string& identifier);
	void createPushForNumber(const std::string& number);
	void createPushForVariable(const std::string& identifier);
	void createPopToVariable(const std::string& identifier);
	void createOperator(const Operator& operator_object);
	void createFunctionCall(const std::string& identifier);
	void createJump(void);
	void createLabel(const std::string& label);
	void createConditionalJump(void);
	void createLabelForConditionalJump(void);
	void checkForErrors(void);

private:
	AssemblerCode     assembler_code;
	StringConstantMap string_constants;
	utils::StringList variables;
	utils::StringList functions;
	utils::StringList labels;
	utils::StringList conditional_jump_ids;
	int               last_conditional_jump_id;

	void testIdentifierConflict(const std::string& identifier) const;
	void testLabelConflict(const std::string& label) const;
};

}
}
#endif
