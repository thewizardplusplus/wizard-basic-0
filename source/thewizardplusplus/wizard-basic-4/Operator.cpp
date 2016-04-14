#include "Operator.h"

using namespace thewizardplusplus::wizard_basic_4;

Operator::Operator(void) :
	valid(false)
{}

Operator::Operator(const std::string& token, int precedence,
	OperatorAssociativity::Types associativity)
:
	valid(true),
	token(token),
	precedence(precedence),
	associativity(associativity)
{}

bool Operator::isValid(void) const {
	return valid;
}

std::string Operator::getToken(void) const {
	return token;
}

int Operator::getPrecedence(void) const {
	return precedence;
}

OperatorAssociativity::Types Operator::getAssociativity(void) const {
	return associativity;
}
