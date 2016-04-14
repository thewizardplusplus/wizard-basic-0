#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include "CodeLines.h"

namespace thewizard {
namespace nicole_compiler {

class Preprocessor {
public:
	virtual ~Preprocessor(void);
	virtual void preprocess(CodeLines& code_lines) = 0;
};

}
}
#endif
