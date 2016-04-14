#include "PreprocessorManager.h"
#include "exceptions/UnableToOpenSourceFile.h"
#include "Preprocessor.h"
#include <fstream>

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::wizard_basic_4::exceptions;

PreprocessorManager::PreprocessorManager(const PreprocessorList& preprocessors)
:
	preprocessors(preprocessors)
{}

PreprocessorManager::~PreprocessorManager(void) {
	PreprocessorList::iterator i = preprocessors.begin();
	for (; i != preprocessors.end(); ++i) {
		delete (*i);
		*i = NULL;
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
