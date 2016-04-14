#ifndef COMMANDLINEARGUMENTS_H
#define COMMANDLINEARGUMENTS_H

#include "StringList.h"

namespace thewizardplusplus {
namespace utils {

class CommandLineArguments {
public:
	static const size_t UNLIMITED_NUMBER_OF_ARGUMENTS = -1;

	CommandLineArguments(size_t limit_of_number_of_arguments1 =
		UNLIMITED_NUMBER_OF_ARGUMENTS, size_t limit_of_number_of_arguments2 =
		UNLIMITED_NUMBER_OF_ARGUMENTS);
	virtual ~CommandLineArguments(void);
	void set(const char * const * const arguments, size_t number_of_arguments);
	std::string getProgramPath(void) const;

protected:
	std::string getNextArgument(void);
	virtual void processArgument(const std::string& argument) = 0;

private:
	size_t                     minimal_number_of_arguments;
	size_t                     maximal_number_of_arguments;
	StringList                 arguments;
	StringList::const_iterator iterator;
	std::string                program_path;
};

}
}
#endif
