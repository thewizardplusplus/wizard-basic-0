#include "SeparatorNotFound.h"
#include "../../utils/Formatter.h"

using namespace thewizardplusplus::wizard_basic_0::exceptions;
using namespace thewizardplusplus::utils;

const std::string SeparatorNotFound::MESSAGE = "in the statement \"%0%\" the "
	"separator \"%1%\" isn't found";

SeparatorNotFound::SeparatorNotFound(StatementCompiler* statement_compiler) :
	CompileException(Formatter(MESSAGE).setArgument(statement_compiler
		->getMark()).setArgument(statement_compiler->getSeparator()))
{}
