#ifndef LINETRIMMER_H
#define LINETRIMMER_H

#include "Preprocessor.h"

namespace thewizard {
namespace nicole_compiler {

class LineTrimmer : public Preprocessor {
public:
	virtual void preprocess(CodeLines& code_lines);
};

}
}
#endif
