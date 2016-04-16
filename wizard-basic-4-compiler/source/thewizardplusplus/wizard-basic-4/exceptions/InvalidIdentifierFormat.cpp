#include "InvalidIdentifierFormat.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_4::exceptions;
using namespace thewizardplusplus::utils;

const std::string InvalidIdentifierFormat::MESSAGE = "invalid identifier "
	"\"%0%\"";

InvalidIdentifierFormat::InvalidIdentifierFormat(const std::string& identifier)
:
	CompileException(Formatter(MESSAGE).setArgument(identifier))
{}
