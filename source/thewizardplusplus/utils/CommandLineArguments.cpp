#include "CommandLineArguments.h"
#include "exceptions/InvalidNumberOfCommandLineArguments.h"
#include "exceptions/NullPointerToArrayOfCommandLineArguments.h"
#include "exceptions/NullPointerToCommandLineArgument.h"
#include "FileInfo.h"

using namespace thewizardplusplus::utils;
using namespace thewizardplusplus::utils::exceptions;

CommandLineArguments::CommandLineArguments(size_t limit_of_number_of_arguments1,
	size_t limit_of_number_of_arguments2)
:
	minimal_number_of_arguments(UNLIMITED_NUMBER_OF_ARGUMENTS),
	maximal_number_of_arguments(UNLIMITED_NUMBER_OF_ARGUMENTS)
{
	minimal_number_of_arguments = std::min(limit_of_number_of_arguments1,
		limit_of_number_of_arguments2);
	maximal_number_of_arguments = std::max(limit_of_number_of_arguments1,
		limit_of_number_of_arguments2);
}

CommandLineArguments::~CommandLineArguments(void) {}

void CommandLineArguments::set(const char * const * const arguments,
	size_t number_of_arguments)
{
	if (arguments == NULL) {
		throw NullPointerToArrayOfCommandLineArguments();
	}

	unsigned int actual_number_of_arguments = number_of_arguments - 1;
	if (actual_number_of_arguments < minimal_number_of_arguments ||
		actual_number_of_arguments > maximal_number_of_arguments)
	{
		throw InvalidNumberOfCommandLineArguments(number_of_arguments,
			minimal_number_of_arguments, maximal_number_of_arguments);
	}

	for (size_t i = 0; i < number_of_arguments; i++) {
		const char * const argument = arguments[i];
		if (argument == NULL) {
			throw NullPointerToCommandLineArgument(i);
		}

		this->arguments.push_back(argument);
	}
	iterator = this->arguments.begin();

	std::string argument = getNextArgument();
	program_path = FileInfo(argument).getAbsolutePath();
	while (!argument.empty()) {
		processArgument(argument);
		argument = getNextArgument();
	}
}

std::string CommandLineArguments::getProgramPath(void) const {
	return program_path;
}

std::string CommandLineArguments::getNextArgument(void) {
	if (iterator != arguments.end()) {
		return *iterator++;
	} else {
		return std::string();
	}
}
