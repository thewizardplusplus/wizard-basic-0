#ifndef EMPTYLINEDELETER_H
#define EMPTYLINEDELETER_H

#include "Preprocessor.h"

namespace thewizardplusplus {
namespace nicole_compiler {

class EmptyLineDeleter : public Preprocessor {
public:
	virtual void preprocess(CodeLines& code_lines);
};

}
}
#endif
