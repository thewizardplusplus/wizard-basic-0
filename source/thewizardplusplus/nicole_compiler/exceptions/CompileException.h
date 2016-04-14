#ifndef COMPILEEXCEPTION_H
#define COMPILEEXCEPTION_H

#include <stdexcept>

namespace thewizard {
namespace nicole_compiler {
namespace exceptions {

class CompileException : public std::runtime_error {
public:
	static const std::string MESSAGE;

	CompileException(const std::string& message);
	virtual ~CompileException(void) throw();
	virtual const char* what(void) const throw();
	unsigned long int getLineNumber(void) const;
	void setLineNumber(unsigned long int line_number);

private:
	std::string       message;
	unsigned long int line_number;
};

}
}
}
#endif
