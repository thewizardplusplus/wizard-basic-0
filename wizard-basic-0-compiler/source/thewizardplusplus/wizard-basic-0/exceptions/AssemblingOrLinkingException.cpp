#include "AssemblingOrLinkingException.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;

const std::string AssemblingOrLinkingException::MESSAGE = "Assembling or "
	"linking error.";

AssemblingOrLinkingException::AssemblingOrLinkingException(void) :
	std::runtime_error(MESSAGE)
{}
