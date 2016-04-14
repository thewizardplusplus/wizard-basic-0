#include "PreprocessorManager.h"
#include "exceptions/UnableToOpenSourceFile.h"
#include "Preprocessor.h"
#include <fstream>

using namespace thewizard::nicole_compiler;
using namespace thewizard::nicole_compiler::exceptions;

PreprocessorManager::PreprocessorManager(const PreprocessorList& preprocessors)
:
	preprocessors(preprocessors)
{}

PreprocessorManager::~PreprocessorManager(void) {
	PreprocessorList::const_iterator i = preprocessors.begin();
	for (; i != preprocessors.end(); ++i) {
		delete (*i);
	}
}

CodeLines PreprocessorManager::preprocess(const std::string& absolute_file_path)
{
	std::ifstream in(absolute_file_path.c_str());
	if (!in.is_open()) {
		throw UnableToOpenSourceFile(absolute_file_path);
	}

	CodeLines code_lines;
	unsigned long int line_number = 0;
	std::string buffer;
	while (in.good()) {
		std::getline(in, buffer);
		code_lines[line_number] = buffer;
		line_number++;
	}

	PreprocessorList::const_iterator i = preprocessors.begin();
	for (; i != preprocessors.end(); ++i) {
		(*i)->preprocess(code_lines);
	}

	return code_lines;
}
