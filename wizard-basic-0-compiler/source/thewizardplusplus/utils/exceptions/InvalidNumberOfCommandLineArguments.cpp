#include "InvalidNumberOfCommandLineArguments.h"
#include "../Formatter.h"

using namespace thewizardplusplus::utils::exceptions;
using namespace thewizardplusplus::utils;

const std::string InvalidNumberOfCommandLineArguments::MESSAGE_GENERAL =
	"Invalid number of command line arguments. %0%";
const std::string InvalidNumberOfCommandLineArguments::MESSAGE_FOR_UNKNOWN_ERROR
	= "Unknown error (a negative number of arguments - got %0% arguments).";
const std::string InvalidNumberOfCommandLineArguments::MESSAGE_FOR_OPEN_INTERVAL
	= "Expected %0% or more arguments, but got %1%.";
const std::string InvalidNumberOfCommandLineArguments
	::MESSAGE_FOR_CLOSED_INTERVAL = "Expected %0% to %1% arguments, but got "
	"%2%.";
const std::string InvalidNumberOfCommandLineArguments::MESSAGE_FOR_ONE_ARGUMENT
	= "Expected 1 argument, but got %0%.";
const std::string InvalidNumberOfCommandLineArguments
	::MESSAGE_FOR_SPECIFIC_NUMBER = "Expected %0% arguments, but got %1%.";

InvalidNumberOfCommandLineArguments::InvalidNumberOfCommandLineArguments(
	size_t number_of_arguments, size_t limit_of_number_of_arguments1,
	size_t limit_of_number_of_arguments2)
:
	std::runtime_error(Formatter(MESSAGE_GENERAL).setArgument(constructMessage(
		number_of_arguments, limit_of_number_of_arguments1,
		limit_of_number_of_arguments2)))
{}

std::string InvalidNumberOfCommandLineArguments::constructMessage(
	size_t number_of_arguments, size_t limit_of_number_of_arguments1,
	size_t limit_of_number_of_arguments2) const
{
	size_t minimal_number_of_arguments = std::min(limit_of_number_of_arguments1,
		limit_of_number_of_arguments2);
	size_t maximal_number_of_arguments = std::max(limit_of_number_of_arguments1,
		limit_of_number_of_arguments2);

	int actual_number_of_arguments = number_of_arguments - 1;
	if (actual_number_of_arguments < 0 || (minimal_number_of_arguments ==
		CommandLineArguments::UNLIMITED_NUMBER_OF_ARGUMENTS &&
		maximal_number_of_arguments == CommandLineArguments::
		UNLIMITED_NUMBER_OF_ARGUMENTS))
	{
		return Formatter(MESSAGE_FOR_UNKNOWN_ERROR).setArgument(
			actual_number_of_arguments);
	} else if (maximal_number_of_arguments == CommandLineArguments::
		UNLIMITED_NUMBER_OF_ARGUMENTS)
	{
		return Formatter(MESSAGE_FOR_OPEN_INTERVAL).setArgument(
			minimal_number_of_arguments).setArgument(
			actual_number_of_arguments);
	} else if (minimal_number_of_arguments == maximal_number_of_arguments) {
		if (minimal_number_of_arguments == 1) {
			return Formatter(MESSAGE_FOR_ONE_ARGUMENT).setArgument(
				actual_number_of_arguments);
		} else {
			return Formatter(MESSAGE_FOR_SPECIFIC_NUMBER).setArgument(
				minimal_number_of_arguments).setArgument(
				actual_number_of_arguments);
		}
	} else {
		return Formatter(MESSAGE_FOR_CLOSED_INTERVAL).setArgument(
			minimal_number_of_arguments).setArgument(
			maximal_number_of_arguments).setArgument(
			actual_number_of_arguments);
	}
}
