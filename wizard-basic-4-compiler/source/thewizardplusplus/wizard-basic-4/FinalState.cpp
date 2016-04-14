#include "FinalState.h"
#include "exceptions/UnknownFinalState.h"

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::wizard_basic_4::exceptions;

FinalState::Types FinalState::fromString(const std::string& final_state) {
	FinalState::Types result = FinalState::EXECUTABLE_FILE;
	if (final_state == "p" || final_state == "preprocessed-code") {
		result = FinalState::PREPROCESSED_CODE;
	} else if (final_state == "b" || final_state == "byte-code") {
		result = FinalState::BYTE_CODE;
	} else if (final_state == "a" || final_state == "assembler-code") {
		result = FinalState::ASSEMBLER_CODE;
	} else if (final_state == "e" || final_state == "executable-file") {
		result = FinalState::EXECUTABLE_FILE;
	} else {
		throw UnknownFinalState(final_state);
	}

	return result;
}

std::string FinalState::toString(FinalState::Types final_state) {
	std::string result;
	switch (final_state) {
		case FinalState::PREPROCESSED_CODE:
			result = "PREPROCESSED_CODE";
			break;
		case FinalState::BYTE_CODE:
			result = "BYTE_CODE";
			break;
		case FinalState::ASSEMBLER_CODE:
			result = "ASSEMBLER_CODE";
			break;
		case FinalState::EXECUTABLE_FILE:
			result = "EXECUTABLE_FILE";
			break;
		default:
			throw UnknownFinalState(final_state);
	}

	return result;
}
