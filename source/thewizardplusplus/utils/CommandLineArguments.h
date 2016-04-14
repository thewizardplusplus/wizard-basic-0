#ifndef COMMANDLINEARGUMENTS_H
#define COMMANDLINEARGUMENTS_H

#include "StringList.h"

namespace thewizard {
namespace utils {

class CommandLineArguments {
public:
	static const int UNLIMITED_NUMBER_OF_ARGUMENTS = -1;

	CommandLineArguments(int minimal_number_of_arguments =
		UNLIMITED_NUMBER_OF_ARGUMENTS, int maximal_number_of_arguments =
		UNLIMITED_NUMBER_OF_ARGUMENTS);
	virtual ~CommandLineArguments(void);
	void set(char** arguments, int number_of_arguments);
	std::string getProgramPath(void) const;
	std::string getNextArgument(void);

protected:
	virtual void processArgument(const std::string& argument);

private:
	int                        minimal_number_of_arguments;
	int                        maximal_number_of_arguments;
	StringList                 arguments;
	StringList::const_iterator iterator;
	std::string                program_path;
};

}
}
#endif
