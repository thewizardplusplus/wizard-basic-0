#include "AssemblerModule.h"
#include "exceptions/UndefinedVariable.h"
#include "exceptions/AttemptToConstantChange.h"
#include "exceptions/UndefinedFunction.h"
#include "exceptions/EndWithoutIf.h"
#include "exceptions/IfWithoutEnd.h"
#include "exceptions/IdentifierConflictWithVariable.h"
#include "exceptions/IdentifierConflictWithFunction.h"
#include "exceptions/LabelConflictWithOtherLabel.h"
#include "exceptions/LabelConflictWithConditionalJumps.h"
#include "../utils/Formatter.h"
#include "ExpressionCompiler.h"
#include <algorithm>

using namespace thewizardplusplus::wizard_basic_0;
using namespace thewizardplusplus::wizard_basic_0::exceptions;
using namespace thewizardplusplus::utils;

const std::string AssemblerModule::PUSH_NUMBER_MNEMONIC_NAME =     "pushn";
const std::string AssemblerModule::PUSH_VARIABLE_MNEMONIC_NAME =   "pushv";
const std::string AssemblerModule::POP_VARIABLE_MNEMONIC_NAME =    "popv";
const std::string AssemblerModule::DO_MNEMONIC_NAME =              "do";
const std::string AssemblerModule::CALL_MNEMONIC_NAME =            "call";
const std::string AssemblerModule::LABEL_MNEMONIC_NAME =           "label";
const std::string AssemblerModule::JUMP_MNEMONIC_NAME =            "jmp";
const std::string AssemblerModule::JUMP_IF_ZERO_MNEMONIC_NAME =    "jz";
const std::string AssemblerModule::CONDITIONAL_JUMP_LABEL_FORMAT = "%0%%1%";
const std::string AssemblerModule::CONDITIONAL_JUMP_BASE_LABEL =
	"conditional_jump_";

AssemblerModule::AssemblerModule(void) :
	last_conditional_jump_id(DEFAULT_LAST_CONDITIONAL_JUMP_ID)
{}

AssemblerCode AssemblerModule::getAssemblerCode(void) const {
	return assembler_code;
}

bool AssemblerModule::isDefinedStringConstants(const std::string& identifier)
	const
{
	return string_constants.count(identifier);
}

AssemblerModule::StringConstantMap AssemblerModule::getDefinedStringConstants(
	void) const
{
	return string_constants;
}

bool AssemblerModule::isDefinedVariable(const std::string& identifier) const {
	StringList::const_iterator identifiers_end = variables.end();
	StringList::const_iterator result = std::find(variables.begin(),
		identifiers_end, identifier);
	return result != identifiers_end;
}

StringList AssemblerModule::getDefinedVariables(void) const {
	return variables;
}

bool AssemblerModule::isDefinedFunction(const std::string& identifier) const {
	StringList::const_iterator functions_end = functions.end();
	StringList::const_iterator result = std::find(functions.begin(),
		functions_end, identifier);
	return result != functions_end;
}

bool AssemblerModule::isDefinedLabel(const std::string& label) const {
	StringList::const_iterator labels_end = labels.end();
	StringList::const_iterator result = std::find(labels.begin(),
		labels_end, label);
	return result != labels_end;
}

void AssemblerModule::addStringConstant(const std::string& identifier,
	const std::string& value)
{
	testIdentifierConflict(identifier);
	testLabelConflict(identifier);

	string_constants[identifier] = value;
	variables.push_back(identifier);
}

void AssemblerModule::addVariableIdentifier(const std::string& identifier) {
	testIdentifierConflict(identifier);

	variables.push_back(identifier);
}

void AssemblerModule::addFunctionIdentifier(const std::string& identifier) {
	testIdentifierConflict(identifier);

	functions.push_back(identifier);
}

void AssemblerModule::createPushForNumber(const std::string& number) {
	assembler_code.push_back(AssemblerMnemonic(PUSH_NUMBER_MNEMONIC_NAME,
		number));
}

void AssemblerModule::createPushForVariable(const std::string& identifier) {
	if (!isDefinedVariable(identifier)) {
		throw UndefinedVariable(identifier);
	}

	assembler_code.push_back(AssemblerMnemonic(PUSH_VARIABLE_MNEMONIC_NAME,
		identifier));
}

void AssemblerModule::createPopToVariable(const std::string& identifier) {
	if (!isDefinedVariable(identifier)) {
		throw UndefinedVariable(identifier);
	}
	if (isDefinedStringConstants(identifier)) {
		throw AttemptToConstantChange(identifier);
	}

	assembler_code.push_back(AssemblerMnemonic(POP_VARIABLE_MNEMONIC_NAME,
		identifier));
}

void AssemblerModule::createOperator(const Operator& operator_object) {
	assembler_code.push_back(AssemblerMnemonic(DO_MNEMONIC_NAME, operator_object
		.getToken()));
}

void AssemblerModule::createFunctionCall(const std::string& identifier) {
	if (!isDefinedFunction(identifier)) {
		throw UndefinedFunction(identifier);
	}

	assembler_code.push_back(AssemblerMnemonic(CALL_MNEMONIC_NAME, identifier));
}

void AssemblerModule::createJump(const std::string& label) {
	assembler_code.push_back(AssemblerMnemonic(JUMP_MNEMONIC_NAME, label));
}

void AssemblerModule::createLabel(const std::string& label) {
	testLabelConflict(label);

	labels.push_back(label);
	assembler_code.push_back(AssemblerMnemonic(LABEL_MNEMONIC_NAME, label));
}

void AssemblerModule::createConditionalJump(void) {
	last_conditional_jump_id++;
	std::string label = Formatter(CONDITIONAL_JUMP_LABEL_FORMAT).setArgument(
		CONDITIONAL_JUMP_BASE_LABEL).setArgument(last_conditional_jump_id);
	labels.push_back(label);
	conditional_jump_ids.push_back(label);
	assembler_code.push_back(AssemblerMnemonic(JUMP_IF_ZERO_MNEMONIC_NAME,
		label));
}

void AssemblerModule::createLabelForConditionalJump(void) {
	if (conditional_jump_ids.empty()) {
		throw EndWithoutIf();
	}

	std::string label = conditional_jump_ids.back();
	conditional_jump_ids.pop_back();
	assembler_code.push_back(AssemblerMnemonic(LABEL_MNEMONIC_NAME, label));
}

void AssemblerModule::checkForErrors(void) {
	if (!conditional_jump_ids.empty()) {
		throw IfWithoutEnd();
	}
}

void AssemblerModule::testIdentifierConflict(const std::string& identifier)
	const
{
	if (isDefinedVariable(identifier)) {
		throw IdentifierConflictWithVariable(identifier);
	}
	if (isDefinedFunction(identifier)) {
		throw IdentifierConflictWithFunction(identifier);
	}
}

void AssemblerModule::testLabelConflict(const std::string& label) const {
	if (isDefinedLabel(label)) {
		throw LabelConflictWithOtherLabel(label);
	}
	size_t conditional_label_length = CONDITIONAL_JUMP_BASE_LABEL.length();
	if (label.substr(0, conditional_label_length) == CONDITIONAL_JUMP_BASE_LABEL
		&& ExpressionCompiler::isNumber(label.substr(conditional_label_length)))
	{
		throw LabelConflictWithConditionalJumps();
	}
}
