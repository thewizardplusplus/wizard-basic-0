#include "CommandLineArguments.h"
#include "exceptions/InvalidCommandLineArguments.h"
#include "FileInfo.h"

using namespace thewizard::utils;
using namespace thewizard::utils::exceptions;

CommandLineArguments::CommandLineArguments(int minimal_number_of_arguments,
	int maximal_number_of_arguments)
:
	minimal_number_of_arguments(minimal_number_of_arguments),
	maximal_number_of_arguments(maximal_number_of_arguments)
{}

CommandLineArguments::~CommandLineArguments(void) {}

void CommandLineArguments::set(char** arguments, int number_of_arguments) {
	int actual_number_of_arguments = number_of_arguments - 1;
	if ((minimal_number_of_arguments != UNLIMITED_NUMBER_OF_ARGUMENTS &&
		actual_number_of_arguments < minimal_number_of_arguments) ||
		(maximal_number_of_arguments != UNLIMITED_NUMBER_OF_ARGUMENTS &&
		actual_number_of_arguments > maximal_number_of_arguments))
	{
		throw InvalidCommandLineArguments();
	}

	for (int i = 0; i < number_of_arguments; i++) {
		this->arguments.push_back(arguments[i]);
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

void CommandLineArguments::processArgument(const std::string& argument) {
	(void)argument;
}
