#include "Builder.h"
#include "../utils/os.h"
#include "exceptions/FailedOpenTemporaryFileException.h"
#include "../utils/Formatter.h"
#include "../utils/Console.h"
#include "exceptions/AssemblingOrLinkingException.h"
#include <cstdio>
#include <fstream>
#include <cstdlib>

using namespace thewizardplusplus::wizard_basic_0;
using namespace thewizardplusplus::wizard_basic_0::exceptions;
using namespace thewizardplusplus::utils;

const std::string Builder::ASSEMBLER_SOURCE_EXTENSION =
	#ifdef OS_LINUX
	".s";
	#elif defined(OS_WINDOWS)
	"s";
	#endif
const std::string Builder::COMPILE_COMMAND =
	"gcc "
	"-O3 "
	"-m32 "
	#ifdef OS_WINDOWS
	"-Wl,-subsystem,console "
	#endif
	"-o %2% "
	"%0% "
	"-L%1% "
	"-lwb0r "
	"-lm";

void Builder::build(const std::string& assembler_code, const std::string&
	compiler_path, const std::string& output_path)
{
	std::string temporary_filename = std::tmpnam(NULL) + Builder::
		ASSEMBLER_SOURCE_EXTENSION;
	std::ofstream out(temporary_filename.c_str());
	if (!out.is_open()) {
		throw FailedOpenTemporaryFileException(temporary_filename);
	}
	out << assembler_code << "\n";
	out.close();

	std::string command = Formatter(Builder::COMPILE_COMMAND).setArgument(
		temporary_filename).setArgument(compiler_path).setArgument(
		output_path).toString();
	Console::information() << command;

	int exit_code = std::system(command.c_str());
	if (exit_code) {
		throw AssemblingOrLinkingException();
	}

	std::remove(temporary_filename.c_str());
}
