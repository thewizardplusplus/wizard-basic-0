#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include "CodeLines.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {

class Preprocessor {
public:
	virtual ~Preprocessor(void);
	virtual void preprocess(CodeLines& code_lines) = 0;
};

}
}
#endif
