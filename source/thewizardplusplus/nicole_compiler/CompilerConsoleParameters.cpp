#include "CompilerConsoleParameters.h"
#include "../utils/Console.h"
#include "../utils/Formatter.h"
#include "exceptions/UnknownCommandLineOption.h"
#include "../utils/FileInfo.h"
#include "current_version.h"
#include <cstdlib>

using namespace thewizardplusplus::nicole_compiler;
using namespace thewizardplusplus::utils;
using namespace thewizardplusplus::nicole_compiler::exceptions;

const std::string CompilerConsoleParameters::VERSION_OPTION_SHORT =   "-v";
const std::string CompilerConsoleParameters::VERSION_OPTION_LONG =
	"--version";
const std::string CompilerConsoleParameters::VERSION_MESSAGE =
	"Nicole Compiler, compiler for the programming language Nicole, version "
	"%0%.\n"
	"(c) 2013 thewizardplusplus, http://thewizardplusplus.ru.";
const std::string CompilerConsoleParameters::HELP_OPTION_SHORT =      "-h";
const std::string CompilerConsoleParameters::HELP_OPTION_LONG =
	"--help";
const std::string CompilerConsoleParameters::HELP_MESSAGE =
	"Usage:\n"
	"\tnicole_compiler (option|filename)\n"
	"\n"
	"Option:\n"
	"\t-v, --version - display compiler version;\n"
	"\t-h, --help -    display this information.";
const std::string CompilerConsoleParameters::OPTION_PREFIX_SHORT =    "-";
const std::string CompilerConsoleParameters::OPTION_PREFIX_LONG =     "--";
const std::string CompilerConsoleParameters::UNKNOWN_OPTION_MESSAGE = "Unknown "
	"option \"%0%\".";
#ifdef OS_WINDOWS
const std::string CompilerConsoleParameters::OUTPUT_FILE_EXTENSION =  "exe";
#endif

CompilerConsoleParameters::CompilerConsoleParameters(void) :
	CommandLineArguments(NUMBER_OF_ARGUMENTS, CommandLineArguments::
		UNLIMITED_NUMBER_OF_ARGUMENTS)
{}

std::string CompilerConsoleParameters::getSourcePath(void) const {
	return source_path;
}

std::string CompilerConsoleParameters::getOutputPath(void) const {
	return output_path;
}

void CompilerConsoleParameters::processArgument(const std::string& argument) {
	if (argument == VERSION_OPTION_SHORT || argument == VERSION_OPTION_LONG) {
		Console::information() << Formatter(VERSION_MESSAGE).setArgument(
			CurrentVersion::STRING_VERSION);
		std::exit(EXIT_SUCCESS);
	} else if (argument == HELP_OPTION_SHORT || argument == HELP_OPTION_LONG) {
		Console::information() << HELP_MESSAGE;
		std::exit(EXIT_SUCCESS);
	} else if (argument.substr(0, 1) == OPTION_PREFIX_SHORT || argument.substr(
		0, 2) == OPTION_PREFIX_LONG)
	{
		throw UnknownCommandLineOption(argument);
	} else {
		source_path = argument;
		if (!FileInfo::isAbsolutePath(source_path)) {
			source_path = getProgramPath() + source_path;
		}

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
