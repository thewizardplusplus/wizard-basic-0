#include "LanguageElements.h"
#include "../utils/Formatter.h"
#include <stdexcept>

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::utils;

const std::string LanguageElements::COMMENT_MARK =
	"note";
const std::string LanguageElements::ADD_OPERATOR_TOKEN =
	"+";
const std::string LanguageElements::SUB_OPERATOR_TOKEN =
	"-";
const std::string LanguageElements::MUL_OPERATOR_TOKEN =
	"*";
const std::string LanguageElements::DIV_OPERATOR_TOKEN =
	"/";
const std::string LanguageElements::LESS_OPERATOR_TOKEN =
	"<";
const std::string LanguageElements::MORE_OPERATOR_TOKEN =
	">";
const std::string LanguageElements::EQUAL_OPERATOR_TOKEN =
	"=";
const std::string LanguageElements::AND_OPERATOR_TOKEN =
	"and";
const std::string LanguageElements::OR_OPERATOR_TOKEN =
	"or";
const std::string LanguageElements::NOT_OPERATOR_TOKEN =
	"not";
const std::string LanguageElements::OPENING_BRACKET =
	"(";
const std::string LanguageElements::CLOSING_BRACKET =
	")";
const std::string LanguageElements::FUNCTION_ARGUMENT_SEPARATOR =
	",";
const LanguageElements::FunctionInfoMap LanguageElements::INBUILT_FUNCTIONS =
	LanguageElements::initFunctionInfoMap();

LanguageElements::FunctionInfoMap LanguageElements::initFunctionInfoMap() {
	LanguageElements::FunctionInfoMap inbuilt_functions;
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberAdd", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberSub", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberMul", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberDiv", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberLess", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberMore", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberEqual", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberAnd", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberOr", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"NumberNot", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Sin", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Cos", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Tg", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Arcsin", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Arccos", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Arctg", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Arctg2", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Pow", FunctionInfo(2)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Exp", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Sqrt", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Ln", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Lg", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Abs", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Trunc", FunctionInfo(1)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Rand", FunctionInfo(0)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"ShowString", FunctionInfo(1, false)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"ShowNumber", FunctionInfo(1, false)));
	inbuilt_functions.insert(LanguageElements::FunctionInfoMap::value_type(
		"Exit", FunctionInfo(1, false)));

	return inbuilt_functions;
}

std::string LanguageElements::getOperatorFunction(const std::string&
	operator_identifier)
{
	std::string result;
	if (operator_identifier == LanguageElements::ADD_OPERATOR_TOKEN) {
		result = "NumberAdd";
	} else if (operator_identifier == LanguageElements::SUB_OPERATOR_TOKEN) {
		result = "NumberSub";
	} else if (operator_identifier == LanguageElements::MUL_OPERATOR_TOKEN) {
		result = "NumberMul";
	} else if (operator_identifier == LanguageElements::DIV_OPERATOR_TOKEN) {
		result = "NumberDiv";
	} else if (operator_identifier == LanguageElements::LESS_OPERATOR_TOKEN) {
		result = "NumberLess";
	} else if (operator_identifier == LanguageElements::MORE_OPERATOR_TOKEN) {
		result = "NumberMore";
	} else if (operator_identifier == LanguageElements::EQUAL_OPERATOR_TOKEN) {
		result = "NumberEqual";
	} else if (operator_identifier == LanguageElements::AND_OPERATOR_TOKEN) {
		result = "NumberAnd";
	} else if (operator_identifier == LanguageElements::OR_OPERATOR_TOKEN) {
		result = "NumberOr";
	} else if (operator_identifier == LanguageElements::NOT_OPERATOR_TOKEN) {
		result = "NumberNot";
	} else {
		throw std::runtime_error(Formatter("Unknown operator \"%0%\".")
			.setArgument(operator_identifier).toString());
	}

	return result;
}
