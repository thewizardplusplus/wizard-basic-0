#include "Assembler.h"
#include <stdexcept>

using namespace thewizardplusplus::wizard_basic_0;
using namespace thewizardplusplus::utils;

const std::string Assembler::INVALID_ARGUMENT_MESSAGE = "Unable to construct "
	"Assembler with null AssemblerModule pointer.";

Assembler::Assembler(AssemblerModule* assembler_module) :
	assembler_module(assembler_module)
{
	if (assembler_module == NULL) {
		throw std::invalid_argument(INVALID_ARGUMENT_MESSAGE);
	}
}

Assembler::~Assembler(void) {}

AssemblerModule* Assembler::getAssemblerModule(void) const {
	return assembler_module;
}

std::string Assembler::getAssemblerCode(void) const {
	return assembler_code;
}

void Assembler::assemble(void) {
	assembler_code.clear();

	beforeAssemble();

	AssemblerCode assembler_code = assembler_module->getAssemblerCode();
	AssemblerCode::const_iterator i = assembler_code.begin();
	for (; i != assembler_code.end(); ++i) {
		processAssemblerMnemonic(*i);
	}

	afterAssemble();
}

void Assembler::beforeAssemble(void) {}

void Assembler::afterAssemble(void) {}
