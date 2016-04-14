#include "UnknownFinalState.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;
using namespace thewizardplusplus::utils;

const std::string UnknownFinalState::MESSAGE_FOR_STRING = "Unknown final state "
	"\"%0%\".";
const std::string UnknownFinalState::MESSAGE_FOR_NUMBER = "Unknown final state "
	"%0%.";

UnknownFinalState::UnknownFinalState(const std::string& final_state) :
	std::runtime_error(Formatter(MESSAGE_FOR_STRING).setArgument(final_state))
{}

UnknownFinalState::UnknownFinalState(FinalState::Types final_state) :
	std::runtime_error(Formatter(MESSAGE_FOR_NUMBER).setArgument(static_cast<
		int>(final_state)))
{}
