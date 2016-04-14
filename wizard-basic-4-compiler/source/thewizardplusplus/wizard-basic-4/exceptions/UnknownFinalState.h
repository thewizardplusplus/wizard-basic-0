#ifndef UNKNOWNFINALSTATE_H
#define UNKNOWNFINALSTATE_H

#include "../FinalState.h"
#include <stdexcept>
#include <string>

namespace thewizardplusplus {
namespace wizard_basic_4 {
namespace exceptions {

class UnknownFinalState : public std::runtime_error {
public:
	static const std::string MESSAGE_FOR_STRING;
	static const std::string MESSAGE_FOR_NUMBER;

	UnknownFinalState(const std::string& final_state);
	UnknownFinalState(FinalState::Types final_state);
};

}
}
}
#endif
