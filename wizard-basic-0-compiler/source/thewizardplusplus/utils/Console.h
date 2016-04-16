#ifndef CONSOLE_H
#define CONSOLE_H

#include "ConsoleMessageType.h"
#include "StringConverter.h"
#include <string>
#include <iostream>

namespace thewizardplusplus {
namespace utils {

class Console {
public:
	static Console information(void);
	template<typename Type>
	inline static void information(Type message);
	static Console error(void);
	template<typename Type>
	inline static void error(Type message);
	static std::string question(const std::string& question);

	explicit Console(ConsoleMessageType::Types message_type);
	~Console(void);
	template<typename Type>
	inline Console& operator<<(Type message);
	Console& operator<<(const char* message);
	Console& operator<<(std::string message);
	void emptyLine(void);

private:
	ConsoleMessageType::Types message_type;
	std::string               message;
};

template<typename Type>
void Console::information(Type message) {
	std::cout << message << std::endl;
}

template<typename Type>
void Console::error(Type message) {
	std::cerr << message << std::endl;
}

template<typename Type>
Console& Console::operator<<(Type message) {
	return operator<<(StringConverter::convert(message));
}

}
}
#endif
