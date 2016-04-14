#ifndef LANGUAGEELEMENTS_H
#define LANGUAGEELEMENTS_H

#include "OperatorAssociativity.h"
#include <string>

namespace thewizardplusplus {
namespace nicole_compiler {

class LanguageElements {
public:
	static const std::string                  COMMENT_MARK;
	static const std::string                  ADD_OPERATOR_TOKEN;
	static const int                          ADD_OPERATOR_PRECEDENCE =      4;
	static const OperatorAssociativity::Types ADD_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::LEFT_ASSOCIATIVE;
	static const std::string                  SUB_OPERATOR_TOKEN;
	static const int                          SUB_OPERATOR_PRECEDENCE =      4;
	static const OperatorAssociativity::Types SUB_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::LEFT_ASSOCIATIVE;
	static const std::string                  MUL_OPERATOR_TOKEN;
	static const int                          MUL_OPERATOR_PRECEDENCE =      5;
	static const OperatorAssociativity::Types MUL_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::LEFT_ASSOCIATIVE;
	static const std::string                  DIV_OPERATOR_TOKEN;
	static const int                          DIV_OPERATOR_PRECEDENCE =      5;
	static const OperatorAssociativity::Types DIV_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::LEFT_ASSOCIATIVE;
	static const std::string                  LESS_OPERATOR_TOKEN;
	static const int                          LESS_OPERATOR_PRECEDENCE =     3;
	static const OperatorAssociativity::Types LESS_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::LEFT_ASSOCIATIVE;
	static const std::string                  MORE_OPERATOR_TOKEN;
	static const int                          MORE_OPERATOR_PRECEDENCE =     3;
	static const OperatorAssociativity::Types MORE_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::LEFT_ASSOCIATIVE;
	static const std::string                  EQUAL_OPERATOR_TOKEN;
	static const int                          EQUAL_OPERATOR_PRECEDENCE =    2;
	static const OperatorAssociativity::Types EQUAL_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::LEFT_ASSOCIATIVE;
	static const std::string                  AND_OPERATOR_TOKEN;
	static const int                          AND_OPERATOR_PRECEDENCE =      1;
	static const OperatorAssociativity::Types AND_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::LEFT_ASSOCIATIVE;
	static const std::string                  OR_OPERATOR_TOKEN;
	static const int                          OR_OPERATOR_PRECEDENCE =       0;
	static const OperatorAssociativity::Types OR_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::LEFT_ASSOCIATIVE;
	static const std::string                  NOT_OPERATOR_TOKEN;
	static const int                          NOT_OPERATOR_PRECEDENCE =      6;
	static const OperatorAssociativity::Types NOT_OPERATOR_ASSOCIATIVITY =
		OperatorAssociativity::RIGHT_ASSOCIATIVE;
	static const std::string                  OPENING_BRACKET;
	static const std::string                  CLOSING_BRACKET;
	static const std::string                  FUNCTION_ARGUMENT_SEPARATOR;
	static const std::string                  INBUILT_FUNCTION_SEPARATOR;
	static const std::string                  INBUILT_FUNCTIONS;
};

}
}
#endif
