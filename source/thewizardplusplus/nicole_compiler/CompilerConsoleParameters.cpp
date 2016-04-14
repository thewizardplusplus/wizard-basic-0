#include "CompilerConsoleParameters.h"
#include "../utils/FileInfo.h"
#include "../utils/Console.h"
#include "../utils/Formatter.h"
#include "current_version.h"
#include <cstdlib>

using namespace thewizard::nicole_compiler;
using namespace thewizard::utils;

#ifdef OS_WINDOWS
const std::string CompilerConsoleParameters::OUTPUT_FILE_EXTENSION = "exe";
#endif

const std::string CompilerConsoleParameters::VERSION_KEY_SHORT = "-v";
const std::string CompilerConsoleParameters::VERSION_KEY_LONG =  "--version";
const std::string CompilerConsoleParameters::VERSION_MESSAGE =   "Nicole "
	"compiler, version %0%.\n(c) thewizard, http://the-wizard.ru.";
const std::string CompilerConsoleParameters::HELP_KEY_SHORT =    "-h";
const std::string CompilerConsoleParameters::HELP_KEY_LONG =     "--help";
const std::string CompilerConsoleParameters::HELP_MESSAGE =      "Usage:\n"
	"\tnicole_compiler filename";

CompilerConsoleParameters::CompilerConsoleParameters(void) :
	CommandLineArguments(NUMBER_OF_ARGUMENTS, NUMBER_OF_ARGUMENTS)
{}

std::string CompilerConsoleParameters::getSourcePath(void) const {
	return source_path;
}

std::string CompilerConsoleParameters::getOutputPath(void) const {
	return output_path;
}

void CompilerConsoleParameters::processArgument(const std::string& argument) {
	if (argument == VERSION_KEY_SHORT || argument == VERSION_KEY_LONG) {
		Console::information() << Formatter(VERSION_MESSAGE).setArgument(
			CurrentVersion::STRING_VERSION);
		std::exit(EXIT_SUCCESS);
	} else if (argument == HELP_KEY_SHORT || argument == HELP_KEY_LONG) {
		Console::information() << HELP_MESSAGE;
		std::exit(EXIT_SUCCESS);
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
