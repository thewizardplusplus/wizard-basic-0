#include "StringConverterHelper.h"

namespace thewizard {
namespace utils {

template<>
StringConverterHelper<char>::StringConverterHelper(char value) {
	std::ostringstream out;
	out << static_cast<long int>(value);
	this->value = out.str();
}

template<>
StringConverterHelper<signed char>::StringConverterHelper(signed char value) {
	std::ostringstream out;
	out << static_cast<long int>(value);
	this->value = out.str();
}

template<>
StringConverterHelper<unsigned char>::StringConverterHelper(unsigned char value)
{
	std::ostringstream out;
	out << static_cast<unsigned long int>(value);
	this->value = out.str();
}

template<>
StringConverterHelper<bool>::StringConverterHelper(bool value) {
	if (value) {
		this->value = "true";
	} else {
		this->value = "false";
	}
}

}
}

using namespace thewizard::utils;

StringConverterHelper<const char*>::StringConverterHelper(const char* value) :
	value(value)
{}

StringConverterHelper<const char*>::operator char(void) const {
	return toChar();
}

StringConverterHelper<const char*>::operator signed char(void) const {
	return toSignedChar();
}

StringConverterHelper<const char*>::operator unsigned char(void) const {
	return toUnsignedChar();
}

StringConverterHelper<const char*>::operator short int(void) const {
	return toShortInt();
}

StringConverterHelper<const char*>::operator unsigned short int(void) const {
	return toUnsignedShortInt();
}

StringConverterHelper<const char*>::operator int(void) const {
	return toInt();
}

StringConverterHelper<const char*>::operator unsigned int(void) const {
	return toUnsignedInt();
}

StringConverterHelper<const char*>::operator long int(void) const {
	return toLongInt();
}

StringConverterHelper<const char*>::operator unsigned long int(void) const {
	return toUnsignedLongInt();
}

StringConverterHelper<const char*>::operator float(void) const {
	return toFloat();
}

StringConverterHelper<const char*>::operator double(void) const {
	return toDouble();
}

StringConverterHelper<const char*>::operator long double(void) const {
	return toLongDouble();
}

StringConverterHelper<const char*>::operator bool(void) const {
	return toBool();
}

char StringConverterHelper<const char*>::toChar(void) const {
	long int converted_value = 0l;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

signed char StringConverterHelper<const char*>::toSignedChar(void) const {
	long int converted_value = 0l;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

unsigned char StringConverterHelper<const char*>::toUnsignedChar(void) const {
	unsigned long int converted_value = 0ul;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

short int StringConverterHelper<const char*>::toShortInt(void) const {
	short int converted_value = 0;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

unsigned short int StringConverterHelper<const char*>::toUnsignedShortInt(void)
		const
{
	unsigned short int converted_value = 0u;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

int StringConverterHelper<const char*>::toInt(void) const {
	int converted_value = 0;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

unsigned int StringConverterHelper<const char*>::toUnsignedInt(void) const {
	unsigned int converted_value = 0u;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

long int StringConverterHelper<const char*>::toLongInt(void) const {
	long int converted_value = 0l;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

unsigned long int StringConverterHelper<const char*>::toUnsignedLongInt(void)
	const
{
	unsigned long int converted_value = 0ul;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

float StringConverterHelper<const char*>::toFloat(void) const {
	float converted_value = 0.0f;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

double StringConverterHelper<const char*>::toDouble(void) const {
	double converted_value = 0.0;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

long double StringConverterHelper<const char*>::toLongDouble(void) const {
	long double converted_value = 0.0l;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

bool StringConverterHelper<const char*>::toBool(void) const {
	long double converted_value = StringConverterHelper<std::string>(value)
		.toLongDouble();
	if (value == "true" || converted_value) {
		return true;
	} else {
		return false;
	}
}

StringConverterHelper<std::string>::StringConverterHelper(std::string value) :
	value(value)
{}

StringConverterHelper<std::string>::operator char(void) const {
	return toChar();
}

StringConverterHelper<std::string>::operator signed char(void) const {
	return toSignedChar();
}

StringConverterHelper<std::string>::operator unsigned char(void) const {
	return toUnsignedChar();
}

StringConverterHelper<std::string>::operator short int(void) const {
	return toShortInt();
}

StringConverterHelper<std::string>::operator unsigned short int(void) const {
	return toUnsignedShortInt();
}

StringConverterHelper<std::string>::operator int(void) const {
	return toInt();
}

StringConverterHelper<std::string>::operator unsigned int(void) const {
	return toUnsignedInt();
}

StringConverterHelper<std::string>::operator long int(void) const {
	return toLongInt();
}

StringConverterHelper<std::string>::operator unsigned long int(void) const {
	return toUnsignedLongInt();
}

StringConverterHelper<std::string>::operator float(void) const {
	return toFloat();
}

StringConverterHelper<std::string>::operator double(void) const {
	return toDouble();
}

StringConverterHelper<std::string>::operator long double(void) const {
	return toLongDouble();
}

StringConverterHelper<std::string>::operator bool(void) const {
	return toBool();
}

char StringConverterHelper<std::string>::toChar(void) const {
	long int converted_value = 0l;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

signed char StringConverterHelper<std::string>::toSignedChar(void) const {
	long int converted_value = 0l;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

unsigned char StringConverterHelper<std::string>::toUnsignedChar(void) const {
	unsigned long int converted_value = 0ul;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

short int StringConverterHelper<std::string>::toShortInt(void) const {
	short int converted_value = 0;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

unsigned short int StringConverterHelper<std::string>::toUnsignedShortInt(void)
		const
{
	unsigned short int converted_value = 0u;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

int StringConverterHelper<std::string>::toInt(void) const {
	int converted_value = 0;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

unsigned int StringConverterHelper<std::string>::toUnsignedInt(void) const {
	unsigned int converted_value = 0u;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

long int StringConverterHelper<std::string>::toLongInt(void) const {
	long int converted_value = 0l;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

unsigned long int StringConverterHelper<std::string>::toUnsignedLongInt(void)
	const
{
	unsigned long int converted_value = 0ul;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

float StringConverterHelper<std::string>::toFloat(void) const {
	float converted_value = 0.0f;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

double StringConverterHelper<std::string>::toDouble(void) const {
	double converted_value = 0.0;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

long double StringConverterHelper<std::string>::toLongDouble(void) const {
	long double converted_value = 0.0l;

	std::istringstream in(value);
	in >> converted_value;

	return converted_value;
}

bool StringConverterHelper<std::string>::toBool(void) const {
	long double converted_value = StringConverterHelper<std::string>(value)
		.toLongDouble();
	if (value == "true" || converted_value) {
		return true;
	} else {
		return false;
	}
}
