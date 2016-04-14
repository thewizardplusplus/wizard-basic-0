#ifndef OPERATORLIST_H
#define OPERATORLIST_H

#include "Operator.h"
#include "../utils/StringList.h"

namespace thewizard {
namespace nicole_compiler {

class OperatorList : public std::list<Operator> {
public:
	utils::StringList getOperatorTokens(void) const;
	Operator getOperatorByToken(const std::string& token) const;
};

}
}
#endif
