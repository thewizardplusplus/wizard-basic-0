#ifndef BUILDER_H
#define BUILDER_H

#include <string>

namespace thewizardplusplus {
namespace wizard_basic_0 {

class Builder {
public:
	static const std::string ASSEMBLER_SOURCE_EXTENSION;
	static const std::string COMPILE_COMMAND;

	static void build(const std::string& assembler_code, const std::string&
		compiler_path, const std::string& output_path);
};

}
}
#endif
