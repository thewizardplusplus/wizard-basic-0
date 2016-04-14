#ifndef STRINGCONVERTERHELPER_H
#define STRINGCONVERTERHELPER_H

#include <string>
#include <sstream>

namespace thewizard {
namespace utils {

template<typename Type>
class StringConverterHelper {
public:
	inline StringConverterHelper(Type value);
	inline operator const char*(void) const;
	inline operator std::string(void) const;
	inline std::string toString(void) const;

private:
	std::string value;
};

template<typename Type>
StringConverterHelper<Type>::StringConverterHelper(Type value) {
	std::ostringstream out;
	out << value;
	this->value = out.str();
}

template<typename Type>
StringConverterHelper<Type>::operator const char*(void) const {
	return value.c_str();
}

template<typename Type>
StringConverterHelper<Type>::operator std::string(void) const {
	return value;
}

template<typename Type>
std::string StringConverterHelper<Type>::toString(void) const {
	return value;
}

template<>
class StringConverterHelper<const char*> {
public:
	StringConverterHelper(const char* value);
	operator char(void) const;
	operator signed char(void) const;
	operator unsigned char(void) const;
	operator short int(void) const;
	operator unsigned short int(void) const;
	operator int(void) const;
	operator unsigned int(void) const;
	operator long int(void) const;
	operator unsigned long int(void) const;
	operator float(void) const;
	operator double(void) const;
	operator long double(void) const;
	operator bool(void) const;
	char toChar(void) const;
	signed char toSignedChar(void) const;
	unsigned char toUnsignedChar(void) const;
	short int toShortInt(void) const;
	unsigned short int toUnsignedShortInt(void) const;
	int toInt(void) const;
	unsigned int toUnsignedInt(void) const;
	long int toLongInt(void) const;
	unsigned long int toUnsignedLongInt(void) const;
	float toFloat(void) const;
	double toDouble(void) const;
	long double toLongDouble(void) const;
	bool toBool(void) const;

private:
	std::string value;
};

template<>
class StringConverterHelper<std::string> {
public:
	StringConverterHelper(std::string value);
	operator char(void) const;
	operator signed char(void) const;
	operator unsigned char(void) const;
	operator short int(void) const;
	operator unsigned short int(void) const;
	operator int(void) const;
	operator unsigned int(void) const;
	operator long int(void) const;
	operator unsigned long int(void) const;
	operator float(void) const;
	operator double(void) const;
	operator long double(void) const;
	operator bool(void) const;
	char toChar(void) const;
	signed char toSignedChar(void) const;
	unsigned char toUnsignedChar(void) const;
	short int toShortInt(void) const;
	unsigned short int toUnsignedShortInt(void) const;
	int toInt(void) const;
	unsigned int toUnsignedInt(void) const;
	long int toLongInt(void) const;
	unsigned long int toUnsignedLongInt(void) const;
	float toFloat(void) const;
	double toDouble(void) const;
	long double toLongDouble(void) const;
	bool toBool(void) const;

private:
	std::string value;
};

}
}
#endif
