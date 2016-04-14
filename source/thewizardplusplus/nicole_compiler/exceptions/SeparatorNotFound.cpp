#include "SeparatorNotFound.h"
#include "../../utils/Formatter.h"

using namespace thewizard::nicole_compiler::exceptions;
using namespace thewizard::utils;

const std::string SeparatorNotFound::MESSAGE = "in the statement \"%0%\" the "
	"separator \"%1%\" isn't found";

SeparatorNotFound::SeparatorNotFound(const std::string& mark,
	const std::string& separator)
:
	CompileException(Formatter(MESSAGE).setArgument(mark).setArgument(
		separator))
{}
