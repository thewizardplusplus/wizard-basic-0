#include "CompilerConsoleParameters.h"
#include "../utils/Console.h"
#include "../utils/Formatter.h"
#include "../utils/StringUtils.h"
#include "exceptions/UnknownCommandLineOption.h"
#include "../utils/FileInfo.h"
#include "current_version.h"
#include <cstdlib>

using namespace thewizardplusplus::wizard_basic_0;
using namespace thewizardplusplus::utils;
using namespace thewizardplusplus::wizard_basic_0::exceptions;

const std::string CompilerConsoleParameters::VERSION_OPTION_SHORT =     "-v";
const std::string CompilerConsoleParameters::VERSION_OPTION_LONG =
	"--version";
const std::string CompilerConsoleParameters::VERSION_MESSAGE =
	"Wizard BASIC 0, v%0%\n"
	"Copyright (c) 2013-2016 thewizardplusplus";
const std::string CompilerConsoleParameters::HELP_OPTION_SHORT =        "-h";
const std::string CompilerConsoleParameters::HELP_OPTION_LONG =
	"--help";
const std::string CompilerConsoleParameters::HELP_MESSAGE =
	"Usage:\n"
	"\twb0 -v | --version\n"
	"\twb0 -h | --help\n"
	"\twb0 [-f NAME | --final-state NAME] <filename>\n"
	"\n"
	"Option:\n"
	"\t-v, --version -                display compiler version;\n"
	"\t-h, --help -                   display this information;\n"
	"\t-f NAME, --final-state NAME -  set final state of compilation "
		"(supported: \"p\"/\"preprocessed-code\", "
		"\"b\"/\"byte-code\", "
		"\"a\"/\"assembler-code\" and "
		"\"e\"/\"executable-file\"; "
		"default: \"e\"/\"executable-file\").";
const std::string CompilerConsoleParameters::FINAL_STATE_OPTION_SHORT = "-f";
const std::string CompilerConsoleParameters::FINAL_STATE_OPTION_LONG =
	"--final-state";
const std::string CompilerConsoleParameters::OPTION_PREFIX_SHORT =      "-";
const std::string CompilerConsoleParameters::OPTION_PREFIX_LONG =       "--";
const std::string CompilerConsoleParameters::UNKNOWN_OPTION_MESSAGE =
	"Unknown option \"%0%\".";
#ifdef OS_WINDOWS
const std::string CompilerConsoleParameters::OUTPUT_FILE_EXTENSION =    "exe";
#endif

CompilerConsoleParameters::CompilerConsoleParameters(void) :
	CommandLineArguments(MINIMAL_NUMBER_OF_ARGUMENTS,
		MAXIMAL_NUMBER_OF_ARGUMENTS),
	final_state(FinalState::EXECUTABLE_FILE)
{}

std::string CompilerConsoleParameters::getSourcePath(void) const {
	return source_path;
}

std::string CompilerConsoleParameters::getOutputPath(void) const {
	return output_path;
}

FinalState::Types CompilerConsoleParameters::getFinalState(void) const {
	return final_state;
}

void CompilerConsoleParameters::processArgument(const std::string& argument) {
	if (argument == VERSION_OPTION_SHORT || argument == VERSION_OPTION_LONG) {
		Console::information() << Formatter(VERSION_MESSAGE).setArgument(
			CurrentVersion::STRING_VERSION).toString();
		std::exit(EXIT_SUCCESS);
	} else if (argument == HELP_OPTION_SHORT || argument == HELP_OPTION_LONG) {
		Console::information() << HELP_MESSAGE;
		std::exit(EXIT_SUCCESS);
	} else if (StringUtils::startWith(argument, FINAL_STATE_OPTION_SHORT) ||
		argument == FINAL_STATE_OPTION_LONG || (StringUtils::startWith(argument,
		FINAL_STATE_OPTION_LONG) && argument.find("=") < argument.size() - 1))
	{
		std::string final_state = "unknown";
		if (StringUtils::startWith(argument, FINAL_STATE_OPTION_SHORT)) {
			size_t option_short_size = FINAL_STATE_OPTION_SHORT.size();
			if (argument.size() > option_short_size) {
				final_state = argument.substr(option_short_size);
			} else {
				final_state = getNextArgument();
			}
		} else if (argument == FINAL_STATE_OPTION_LONG) {
			final_state = getNextArgument();
		} else {
			size_t separator_index = argument.find("=");
			final_state = argument.substr(separator_index + 1);
		}

		this->final_state = FinalState::fromString(final_state);
	} else if (StringUtils::startWith(argument, OPTION_PREFIX_SHORT) ||
		StringUtils::startWith(argument, OPTION_PREFIX_LONG))
	{
		throw UnknownCommandLineOption(argument);
	} else {
		source_path = argument;

		FileInfo source(source_path);
		output_path = source.getAbsolutePath() + source.getFilename();
		size_t source_file_extension_length = source.getFileExtension()
			.length();
		if (source_file_extension_length != 0) {
			output_path = output_path.substr(0, output_path.length() -
				source_file_extension_length - 1);
		}
		#ifdef OS_WINDOWS
		output_path += FileInfo::EXTENSION_SEPARATOR + OUTPUT_FILE_EXTENSION;
		#endif
	}
}
