#include "ExpressionCompiler.h"
#include "../utils/StringUtils.h"
#include "Compiler.h"
#include "AssemblerModule.h"
#include "exceptions/MissedFunctionArgumentSeparatorOrOpeningBracket.h"
#include "exceptions/MissedOpeningBracket.h"
#include "exceptions/MissedClosingBracket.h"
#include "exceptions/UnknownExpressionToken.h"
#include <algorithm>
#include <cctype>
#include <cstddef>

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::utils;
using namespace thewizardplusplus::wizard_basic_4::exceptions;

const std::string ExpressionCompiler::INVALID_ARGUMENT_MESSAGE = "Unable to "
	"construct ExpressionCompiler with null Compiler pointer.";
const std::string ExpressionCompiler::WHITESPACE =               " ";
const char        ExpressionCompiler::DOT_SYMBOL =               '.';
const char        ExpressionCompiler::UNDERSCORE_SYMBOL =        '_';

bool ExpressionCompiler::isNumber(const std::string& token) {
	ptrdiff_t number_of_digits = std::count_if(token.begin(), token.end(),
		std::ptr_fun<int, int>(std::isdigit));
	ptrdiff_t number_of_dots = std::count_if(token.begin(), token.end(),
		std::bind1st(std::equal_to<char>(), DOT_SYMBOL));
	return number_of_digits != 0 && (number_of_dots == 0 || number_of_dots == 1)
		&& static_cast<size_t>(number_of_digits + number_of_dots) ==
		token.length();
}

bool ExpressionCompiler::isIdentifier(const std::string& token) {
	ptrdiff_t number_of_digits = std::count_if(token.begin(), token.end(),
		std::ptr_fun<int, int>(std::isdigit));
	ptrdiff_t number_of_letters = std::count_if(token.begin(), token.end(),
		std::ptr_fun<int, int>(std::isalpha));
	ptrdiff_t number_of_underscores = std::count_if(token.begin(), token.end(),
		std::bind1st(std::equal_to<char>(), UNDERSCORE_SYMBOL));
	return (number_of_letters != 0 || number_of_underscores != 0) &&
		static_cast<size_t>(number_of_digits + number_of_letters +
		number_of_underscores) == token.length();
}

ExpressionCompiler::ExpressionCompiler(Compiler* compiler,
	const OperatorList& operators, const std::string& opening_bracket,
	const std::string& closing_bracket,
	const std::string& function_argument_separator)
:
	compiler(compiler),
	operators(operators),
	opening_bracket(opening_bracket),
	closing_bracket(closing_bracket),
	function_argument_separator(function_argument_separator)
{
	if (compiler == NULL) {
		throw std::invalid_argument(INVALID_ARGUMENT_MESSAGE);
	}

	OperatorList::const_iterator i = operators.begin();
	for (; i != operators.end(); ++i) {
		std::string token = (*i).getToken();
		if (!isNumber(token) && !isIdentifier(token)) {
			token_separators.push_back(token);
		}
	}
	token_separators.push_back(WHITESPACE);
	token_separators.push_back(opening_bracket);
	token_separators.push_back(closing_bracket);
	token_separators.push_back(function_argument_separator);
}

void ExpressionCompiler::compile(const std::string& expression_code) {
	utils::StringList tokens = StringUtils::tokenize(expression_code,
		token_separators, true);

	AssemblerModule* assembler_module = compiler->getAssemblerModule();
	StringList stack;
	StringList::const_iterator i = tokens.begin();
	for (; i != tokens.end(); ++i) {
		std::string token = *i;

		if (isNumber(token)) {
			assembler_module->createPushForNumber(token);
		} else if (isIdentifier(token) && !isOperator(token)) {
			if (assembler_module->isDefinedFunction(token)) {
				stack.push_back(token);
			} else {
				assembler_module->createPushForVariable(token);
			}
		} else if (token == function_argument_separator) {
			while (true) {
				if (stack.empty()) {
					throw MissedFunctionArgumentSeparatorOrOpeningBracket();
				}

				std::string token_form_stack = stack.back();
				if (token_form_stack != opening_bracket) {
					stack.pop_back();
					assembler_module->createOperator(operators
						.getOperatorByToken(token_form_stack));
				} else {
					break;
				}
			}
		} else if (isOperator(token)) {
			while (true) {
				if (stack.empty()) {
					break;
				}

				std::string token_form_stack = stack.back();
				if (!isOperator(token_form_stack)) {
					break;
				}

				Operator current_operator = operators.getOperatorByToken(
					token);
				Operator operator_from_stack = operators.getOperatorByToken(
					token_form_stack);
				if ((current_operator.getAssociativity() ==
					OperatorAssociativity::LEFT_ASSOCIATIVE &&
					current_operator.getPrecedence() <=
					operator_from_stack.getPrecedence()) ||
					(current_operator.getAssociativity() ==
					OperatorAssociativity::RIGHT_ASSOCIATIVE &&
					current_operator.getPrecedence() <
					operator_from_stack.getPrecedence()))
				{
					stack.pop_back();
					assembler_module->createOperator(operator_from_stack);
				} else {
					break;
				}
			}

			stack.push_back(token);
		} else if (token == opening_bracket) {
			stack.push_back(token);
		} else if (token == closing_bracket) {
			while (true) {
				if (stack.empty()) {
					throw MissedOpeningBracket();
				}

				std::string token_form_stack = stack.back();
				if (token_form_stack != opening_bracket) {
					stack.pop_back();
					assembler_module->createOperator(operators
						.getOperatorByToken(token_form_stack));
				} else {
					stack.pop_back();
					break;
				}
			}

			if (!stack.empty()) {
				std::string token_form_stack = stack.back();
				if (assembler_module->isDefinedFunction(token_form_stack)) {
					stack.pop_back();
					assembler_module->createFunctionCall(token_form_stack);
				}
			}
		} else {
			throw UnknownExpressionToken(token);
		}
	}

	while (!stack.empty()) {
		std::string token_form_stack = stack.back();
		if (token_form_stack == opening_bracket) {
			throw MissedClosingBracket();
		} else {
			stack.pop_back();
			assembler_module->createOperator(operators.getOperatorByToken(
				token_form_stack));
		}
	}
}

bool ExpressionCompiler::isOperator(const std::string& token) const {
	return operators.getOperatorByToken(token).isValid();
}
