#ifndef COMPILERCONSOLEPARAMETERS_H
#define COMPILERCONSOLEPARAMETERS_H

#include "../utils/CommandLineArguments.h"
#include "../utils/os.h"

namespace thewizard {
namespace nicole_compiler {

class CompilerConsoleParameters : public utils::CommandLineArguments {
public:
	static const int         NUMBER_OF_ARGUMENTS = 1;
	static const std::string VERSION_KEY_SHORT;
	static const std::string VERSION_KEY_LONG;
	static const std::string VERSION_MESSAGE;
	static const std::string HELP_KEY_SHORT;
	static const std::string HELP_KEY_LONG;
	static const std::string HELP_MESSAGE;
	#ifdef OS_WINDOWS
	static const std::string OUTPUT_FILE_EXTENSION;
	#endif

	CompilerConsoleParameters(void);
	std::string getSourcePath(void) const;
	std::string getOutputPath(void) const;

protected:
	virtual void processArgument(const std::string& argument);

private:
	std::string source_path;
	std::string output_path;
};

}
}
#endif
