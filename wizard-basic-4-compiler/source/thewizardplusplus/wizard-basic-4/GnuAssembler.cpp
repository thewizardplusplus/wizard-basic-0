#include "GnuAssembler.h"
#include "../utils/StringConverter.h"
#include "LanguageElements.h"
#include "../utils/Formatter.h"
#include "FunctionInfo.h"
#include "../utils/os.h"
#include <algorithm>
#include <stdexcept>

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::utils;

GnuAssembler::GnuAssembler(AssemblerModule* assembler_module) :
	Assembler(assembler_module)
{}

std::string GnuAssembler::getAssemblerCode(void) const {
	return assembler_code;
}

void GnuAssembler::beforeAssemble(void) {
	assembler_code +=
		"\t.text\n"
		"\t.global _start\n"
		"\t.type   _start, @function\n"
		"_start:\n";

	size_t number_of_variables = getAssemblerModule()->getDefinedVariables()
		.size() - getAssemblerModule()->getDefinedStringConstants().size();
	if (number_of_variables != 0) {
		assembler_code += "\tenter " + StringConverter::convert(4 *
			number_of_variables) + ", 0\n" + "\t\n";
	}
}

void GnuAssembler::processAssemblerMnemonic(
	const AssemblerMnemonic& assembler_mnemonic)
{
	std::string mnemonic = assembler_mnemonic.getMnemonic();
	if (mnemonic == AssemblerModule::PUSH_NUMBER_MNEMONIC_NAME) {
		assembler_code +=
			"\tflds " + getFloatConstantName(assembler_mnemonic.getOperand()) +
			"\n" +
			"\tsubl $4, %esp\n" +
			"\tfstp (%esp)\n" +
			"\tmovl (%esp), %eax\n" +
			"\taddl $4, %esp\n" +
			"\tpushl %eax\n";
	} else if (mnemonic == AssemblerModule::PUSH_VARIABLE_MNEMONIC_NAME) {
		assembler_code += "\tpushl " + StringConverter::convert(
			getVariableShift(assembler_mnemonic.getOperand())) + "(%ebp)\n";
	} else if (mnemonic == AssemblerModule::POP_VARIABLE_MNEMONIC_NAME) {
		assembler_code += "\tpopl " + StringConverter::convert(getVariableShift(
			assembler_mnemonic.getOperand())) + "(%ebp)\n";
	} else if (mnemonic == AssemblerModule::DO_MNEMONIC_NAME) {
		std::string operator_identifier = assembler_mnemonic.getOperand();
		std::string function_name = LanguageElements::getOperatorFunction(
			operator_identifier);
		makeFunctionCall(function_name);
	} else if (mnemonic == AssemblerModule::CALL_MNEMONIC_NAME) {
		std::string function_name = assembler_mnemonic.getOperand();
		makeFunctionCall(function_name);
	} else if (mnemonic == AssemblerModule::LABEL_MNEMONIC_NAME) {
		assembler_code += assembler_mnemonic.getOperand() + ":\n";
	} else if (mnemonic == AssemblerModule::JUMP_MNEMONIC_NAME) {
		assembler_code += "\tjmp " + assembler_mnemonic.getOperand() + "\n";
	} else if (mnemonic == AssemblerModule::JUMP_IF_ZERO_MNEMONIC_NAME) {
		assembler_code +=
			std::string("\tcmp $0, (%esp)\n")
			+ "\tpop %eax\n"
			+ "\tje " + assembler_mnemonic.getOperand() + "\n";
	} else {
		throw std::runtime_error("Unknown assembler mnemonic.");
	}
}

void GnuAssembler::afterAssemble(void) {
	assembler_code +=
		"\t\n"
		#ifndef OS_WINDOWS
		"\tcall Exit\n"
		#else
		"\tcall _Exit\n"
		#endif
		"\t\n"
		"\t.data\n";

	FloatConstantMap::const_iterator i = float_constants.begin();
	for (; i != float_constants.end(); ++i) {
		assembler_code +=
			i->second + ":\n" +
			"\t.float  " + i->first + "\n";
	}

	AssemblerModule::StringConstantMap string_constants = getAssemblerModule()
		->getDefinedStringConstants();
	AssemblerModule::StringConstantMap::const_iterator j = string_constants
		.begin();
	for (; j != string_constants.end(); ++j) {
		assembler_code +=
			j->first + ":\n" +
			"\t.string \"" + j->second + "\"\n";
	}

	assembler_code = assembler_code.substr(0, assembler_code.size() - 1);
}

std::string GnuAssembler::getFloatConstantName(const std::string& value) {
	FloatConstantMap::const_iterator i = float_constants.find(value);
	if (i != float_constants.end()) {
		return i->second;
	} else {
		std::string name = "FLOAT_CONSTANT" + StringConverter::convert(
			float_constants.size());
		float_constants[value] = name;
		return name;
	}
}

int GnuAssembler::getVariableShift(const std::string& identifier) const {
	StringList variables = getAssemblerModule()->getDefinedVariables();
	StringList::iterator i = std::find(variables.begin(), variables.end(),
		identifier);
	if (i != variables.end()) {
		return -4 * std::distance(variables.begin(), i);
	} else {
		throw std::runtime_error("Undefined variable.");
	}
}

void GnuAssembler::makeFunctionCall(const std::string& function_name) {
	LanguageElements::FunctionInfoMap::const_iterator function_info =
		LanguageElements::INBUILT_FUNCTIONS.find(function_name);
	if (function_info == LanguageElements::INBUILT_FUNCTIONS.end()) {
		throw std::runtime_error(Formatter("Unknown function \"%0%\".")
			.setArgument(function_name).toString());
	}

	assembler_code += std::string("\tcall ")
		#ifdef OS_WINDOWS
		+ "_"
		#endif
		+ function_name
		+ "\n";

	size_t size_of_arguments = 4 * function_info->second.getNumberOfArguments();
	if (size_of_arguments > 0) {
		assembler_code += "\taddl $"
			+ StringConverter::convert(size_of_arguments)
			+ ", %esp\n";
	}

	if (function_info->second.hasReturnValue()) {
		assembler_code += "\tsubl $4, %esp\n"
			"\tfstps (%esp)\n";
	}
}
