#include "UnableToOpenSourceFile.h"
#include "../../utils/Formatter.h"

using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string UnableToOpenSourceFile::MESSAGE = "Unable to open source "
	"file \"%0%\".";

UnableToOpenSourceFile::UnableToOpenSourceFile(const std::string& filname) :
	std::runtime_error(Formatter(MESSAGE).setArgument(filname))
{}
