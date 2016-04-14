#ifndef OPERATOR_H
#define OPERATOR_H

#include "OperatorAssociativity.h"
#include <string>

namespace thewizardplusplus {
namespace nicole_compiler {

class Operator {
public:
	Operator(void);
	Operator(const std::string& token, int precedence,
		OperatorAssociativity::Types associativity =
		OperatorAssociativity::LEFT_ASSOCIATIVE);
	bool isValid(void) const;
	std::string getToken(void) const;
	int getPrecedence(void) const;
	OperatorAssociativity::Types getAssociativity(void) const;

private:
	bool                         valid;
	std::string                  token;
	int                          precedence;
	OperatorAssociativity::Types associativity;
};

}
}
#endif
