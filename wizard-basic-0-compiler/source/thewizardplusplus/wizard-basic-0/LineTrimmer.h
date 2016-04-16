#ifndef LINETRIMMER_H
#define LINETRIMMER_H

#include "Preprocessor.h"

namespace thewizardplusplus {
namespace wizard_basic_0 {

class LineTrimmer : public Preprocessor {
public:
	virtual void preprocess(CodeLines& code_lines);
};

}
}
#endif
