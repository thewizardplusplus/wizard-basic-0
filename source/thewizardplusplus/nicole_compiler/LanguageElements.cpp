#include "LanguageElements.h"

using namespace thewizardplusplus::nicole_compiler;

const std::string LanguageElements::COMMENT_MARK =                "note";
const std::string LanguageElements::ADD_OPERATOR_TOKEN =          "+";
const std::string LanguageElements::SUB_OPERATOR_TOKEN =          "-";
const std::string LanguageElements::MUL_OPERATOR_TOKEN =          "*";
const std::string LanguageElements::DIV_OPERATOR_TOKEN =          "/";
const std::string LanguageElements::LESS_OPERATOR_TOKEN =         "<";
const std::string LanguageElements::MORE_OPERATOR_TOKEN =         ">";
const std::string LanguageElements::EQUAL_OPERATOR_TOKEN =        "=";
const std::string LanguageElements::AND_OPERATOR_TOKEN =          "and";
const std::string LanguageElements::OR_OPERATOR_TOKEN =           "or";
const std::string LanguageElements::NOT_OPERATOR_TOKEN =          "not";
const std::string LanguageElements::OPENING_BRACKET =             "(";
const std::string LanguageElements::CLOSING_BRACKET =             ")";
const std::string LanguageElements::FUNCTION_ARGUMENT_SEPARATOR = ",";
const std::string LanguageElements::INBUILT_FUNCTION_SEPARATOR =  " ";
const std::string LanguageElements::INBUILT_FUNCTIONS =
	std::string() +
	"ShowString" +     LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"ShowNumber" +     LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"StartStopwatch" + LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"GetElapsedTime" + LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Exit" +           LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Sin" +            LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Cos" +            LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Tg" +             LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Arcsin" +         LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Arccos" +         LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Arctg" +          LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Sh" +             LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Ch" +             LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Th" +             LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Exponent" +       LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Ln" +             LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Lg" +             LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Modulus" +        LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Power" +          LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Integer" +        LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Random" +         LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"SquareRoot" +     LanguageElements::INBUILT_FUNCTION_SEPARATOR +
	"Angle";
