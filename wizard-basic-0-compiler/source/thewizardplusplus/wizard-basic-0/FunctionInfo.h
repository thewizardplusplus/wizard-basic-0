#ifndef FUNCTIONINFO_H
#define FUNCTIONINFO_H

#include <cstdlib>

namespace thewizardplusplus {
namespace wizard_basic_0 {

class FunctionInfo {
public:
	FunctionInfo(size_t number_of_arguments, bool return_value = true);
	size_t getNumberOfArguments() const;
	bool hasReturnValue() const;

private:
	size_t number_of_arguments;
	bool   return_value;
};

}
}
#endif
