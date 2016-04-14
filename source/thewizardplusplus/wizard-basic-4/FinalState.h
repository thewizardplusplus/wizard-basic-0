#ifndef FINALSTATE_H
#define FINALSTATE_H

#include <string>

namespace thewizardplusplus {
namespace wizard_basic_4 {

class FinalState {
public:
	enum Types {
		PREPROCESSED_CODE,
		BYTE_CODE,
		ASSEMBLER_CODE,
		EXECUTABLE_FILE
	};

	static Types fromString(const std::string& final_state);
	static std::string toString(Types final_state);
};

}
}
#endif
