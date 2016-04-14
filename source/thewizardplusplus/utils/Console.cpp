#include "Console.h"

using namespace thewizardplusplus::utils;

Console Console::information(void) {
	return Console(ConsoleMessageType::INFORMATION);
}

Console Console::error(void) {
	return Console(ConsoleMessageType::ERROR);
}

std::string Console::question(const std::string& question) {
	std::cout << question;

	std::string answer;
	std::cin >> answer;
	return answer;
}

Console::Console(ConsoleMessageType::Types message_type) :
	message_type(message_type)
{}

Console::~Console(void) {
	switch (message_type) {
	case ConsoleMessageType::ERROR:
		Console::error(message);
		break;
	case ConsoleMessageType::INFORMATION:
	default:
		Console::information(message);
		break;
	}
}

Console& Console::operator<<(const char* message) {
	return operator<<(std::string(message));
}

Console& Console::operator<<(std::string message) {
	this->message += message;
	return *this;
}

void Console::emptyLine(void) {}
