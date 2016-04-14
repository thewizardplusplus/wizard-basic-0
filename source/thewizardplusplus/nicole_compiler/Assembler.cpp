#include "Assembler.h"
#include "../utils/FileInfo.h"
#include <stdexcept>

using namespace thewizard::nicole_compiler;
using namespace thewizard::utils;

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

void Assembler::assemble(const std::string& output_filename) {
	this->output_filename = output_filename;
	beforeAssemble();

	AssemblerModule::AssemblerCode assembler_code = assembler_module
		->getAssemblerCode();
	AssemblerModule::AssemblerCode::const_iterator i = assembler_code.begin();
	for (; i != assembler_code.end(); ++i) {
		processAssemblerMnemonic(*i);
	}

	afterAssemble();
}

void Assembler::beforeAssemble(void) {}

void Assembler::afterAssemble(void) {}
