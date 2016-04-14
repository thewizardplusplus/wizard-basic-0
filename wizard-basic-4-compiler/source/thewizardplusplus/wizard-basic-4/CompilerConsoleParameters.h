#ifndef COMPILERCONSOLEPARAMETERS_H
#define COMPILERCONSOLEPARAMETERS_H

#include "../utils/CommandLineArguments.h"
#include "../utils/os.h"
#include "FinalState.h"

namespace thewizardplusplus {
namespace wizard_basic_4 {

class CompilerConsoleParameters : public utils::CommandLineArguments {
public:
	static const int         MINIMAL_NUMBER_OF_ARGUMENTS = 1;
	static const int         MAXIMAL_NUMBER_OF_ARGUMENTS = 3;
	static const std::string VERSION_OPTION_SHORT;
	static const std::string VERSION_OPTION_LONG;
	static const std::string VERSION_MESSAGE;
	static const std::string HELP_OPTION_SHORT;
	static const std::string HELP_OPTION_LONG;
	static const std::string HELP_MESSAGE;
	static const std::string FINAL_STATE_OPTION_SHORT;
	static const std::string FINAL_STATE_OPTION_LONG;
	static const std::string OPTION_PREFIX_SHORT;
	static const std::string OPTION_PREFIX_LONG;
	static const std::string UNKNOWN_OPTION_MESSAGE;
	#ifdef OS_WINDOWS
	static const std::string OUTPUT_FILE_EXTENSION;
	#endif

	CompilerConsoleParameters(void);
	std::string getSourcePath(void) const;
	std::string getOutputPath(void) const;
	FinalState::Types getFinalState(void) const;

protected:
	virtual void processArgument(const std::string& argument);

private:
	std::string       source_path;
	std::string       output_path;
	FinalState::Types final_state;
};

}
}
#endif
