#include "UnspecifiedSourceFile.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;

const std::string UnspecifiedSourceFile::MESSAGE = "Unspecified source file.";

UnspecifiedSourceFile::UnspecifiedSourceFile(void) :
	std::runtime_error(MESSAGE)
{}
