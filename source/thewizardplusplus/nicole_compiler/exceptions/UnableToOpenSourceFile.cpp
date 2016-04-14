#include "UnableToOpenSourceFile.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::nicole_compiler::exceptions;
using namespace thewizardplusplus::utils;

const std::string UnableToOpenSourceFile::MESSAGE = "Unable to open source "
	"file \"%0%\".";

UnableToOpenSourceFile::UnableToOpenSourceFile(const std::string& filename) :
	std::runtime_error(Formatter(MESSAGE).setArgument(filename))
{}
