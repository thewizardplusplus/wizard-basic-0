#ifndef PREPROCESSORMANAGER_H
#define PREPROCESSORMANAGER_H

#include "CodeLines.h"
#include <list>

namespace thewizardplusplus {
namespace wizard_basic_4 {

class Preprocessor;

class PreprocessorManager {
public:
	typedef std::list<Preprocessor*> PreprocessorList;

	explicit PreprocessorManager(const PreprocessorList& preprocessors);
	~PreprocessorManager(void);
	CodeLines preprocess(const std::string& absolute_file_path);

private:
	PreprocessorList preprocessors;
};

}
}
#endif
