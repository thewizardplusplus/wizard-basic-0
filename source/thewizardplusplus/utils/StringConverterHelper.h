#ifndef STRINGCONVERTERHELPER_H
#define STRINGCONVERTERHELPER_H

#include <string>
#include <sstream>

#define STRING_CONVERTER_HELPER_FOR_NUMBER_CONSTRUCTOR_WITH_WRAPPER_IMPLIMENTATION( \
	number_type, wrapper_type) \
	template<> \
	StringConverterHelper<number_type>::StringConverterHelper( \
		number_type value) \
	{ \
		std::ostringstream out; \
		out << static_cast<wrapper_type>(value); \
		this->value = out.str(); \
	}
#define STRING_CONVERTER_HELPER_FOR_NUMBER_CONSTRUCTOR_IMPLIMENTATION( \
	number_type) \
	STRING_CONVERTER_HELPER_FOR_NUMBER_CONSTRUCTOR_WITH_WRAPPER_IMPLIMENTATION( \
		number_type, number_type)
#define STRING_CONVERTER_HELPER_FOR_STRING_DEFINITION(string_type) \
	template<> \
	class StringConverterHelper<string_type> { \
	public: \
		StringConverterHelper(string_type value); \
		operator char(void) const; \
		operator signed char(void) const; \
		operator unsigned char(void) const; \
		operator short int(void) const; \
		operator unsigned short int(void) const; \
		operator int(void) const; \
		operator unsigned int(void) const; \
		operator long int(void) const; \
		operator unsigned long int(void) const; \
		operator float(void) const; \
		operator double(void) const; \
		operator long double(void) const; \
		operator bool(void) const; \
		char toChar(void) const; \
		signed char toSignedChar(void) const; \
		unsigned char toUnsignedChar(void) const; \
		short int toShortInt(void) const; \
		unsigned short int toUnsignedShortInt(void) const; \
		int toInt(void) const; \
		unsigned int toUnsignedInt(void) const; \
		long int toLongInt(void) const; \
		unsigned long int toUnsignedLongInt(void) const; \
		float toFloat(void) const; \
		double toDouble(void) const; \
		long double toLongDouble(void) const; \
		bool toBool(void) const; \
	private: \
		std::string value; \
	}
#define STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_WITH_MEDIATOR_IMPLIMENTATION( \
	number_type, mediator_type) \
	mediator_type converted_value = 0; \
	std::istringstream in(value); \
	in >> converted_value; \
	return static_cast<number_type>(converted_value)
#define STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
	number_type) \
	STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_WITH_MEDIATOR_IMPLIMENTATION( \
		number_type, number_type)
#define STRING_CONVERTER_HELPER_FOR_STRING_IMPLEMENTATION(string_type) \
	StringConverterHelper<string_type>::StringConverterHelper( \
		string_type value) \
	: \
		value(value) \
	{} \
	StringConverterHelper<string_type>::operator char(void) const { \
		return toChar(); \
	} \
	StringConverterHelper<string_type>::operator signed char(void) const { \
		return toSignedChar(); \
	} \
	StringConverterHelper<string_type>::operator unsigned char(void) const { \
		return toUnsignedChar(); \
	} \
	StringConverterHelper<string_type>::operator short int(void) const { \
		return toShortInt(); \
	} \
	StringConverterHelper<string_type>::operator unsigned short int(void) \
		const \
	{ \
		return toUnsignedShortInt(); \
	} \
	StringConverterHelper<string_type>::operator int(void) const { \
		return toInt(); \
	} \
	StringConverterHelper<string_type>::operator unsigned int(void) const { \
		return toUnsignedInt(); \
	} \
	StringConverterHelper<string_type>::operator long int(void) const { \
		return toLongInt(); \
	} \
	StringConverterHelper<string_type>::operator unsigned long int(void) \
		const \
	{ \
		return toUnsignedLongInt(); \
	} \
	StringConverterHelper<string_type>::operator float(void) const { \
		return toFloat(); \
	} \
	StringConverterHelper<string_type>::operator double(void) const { \
		return toDouble(); \
	} \
	StringConverterHelper<string_type>::operator long double(void) const { \
		return toLongDouble(); \
	} \
	StringConverterHelper<string_type>::operator bool(void) const { \
		return toBool(); \
	} \
	char StringConverterHelper<string_type>::toChar(void) const { \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_WITH_MEDIATOR_IMPLIMENTATION( \
			char, long int); \
	} \
	signed char StringConverterHelper<string_type>::toSignedChar(void) const { \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_WITH_MEDIATOR_IMPLIMENTATION( \
			signed char, long int); \
	} \
	unsigned char StringConverterHelper<string_type>::toUnsignedChar(void) \
		const \
	{ \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_WITH_MEDIATOR_IMPLIMENTATION( \
			unsigned char, unsigned long int); \
	} \
	short int StringConverterHelper<string_type>::toShortInt(void) const { \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
			short int); \
	} \
	unsigned short int StringConverterHelper<string_type>::toUnsignedShortInt( \
		void) const \
	{ \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
			unsigned short int); \
	} \
	int StringConverterHelper<string_type>::toInt(void) const { \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
			int); \
	} \
	unsigned int StringConverterHelper<string_type>::toUnsignedInt(void) \
		const \
	{ \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
			unsigned int); \
	} \
	long int StringConverterHelper<string_type>::toLongInt(void) const { \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
			long int); \
	} \
	unsigned long int StringConverterHelper<string_type>::toUnsignedLongInt( \
		void) const \
	{ \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
			unsigned long int); \
	} \
	float StringConverterHelper<string_type>::toFloat(void) const { \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
			float); \
	} \
	double StringConverterHelper<string_type>::toDouble(void) const { \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
			double); \
	} \
	long double StringConverterHelper<string_type>::toLongDouble(void) const { \
		STRING_CONVERTER_HELPER_FOR_STRING_METHOD_CONVERSION_IMPLIMENTATION( \
			long double); \
	} \
	bool StringConverterHelper<string_type>::toBool(void) const { \
		long double converted_value = StringConverterHelper<std::string>( \
			value).toLongDouble(); \
		if (value == "true" || converted_value) { \
			return true; \
		} else { \
			return false; \
		} \
	} \
	extern int dummy

namespace thewizardplusplus {
namespace utils {

template<typename Type>
class StringConverterHelper {
public:
	inline StringConverterHelper(Type value);
	inline operator std::string(void) const;
	inline std::string toString(void) const;

private:
	std::string value;
};

template<typename Type>
StringConverterHelper<Type>::StringConverterHelper(Type value) {
	std::string string_value;
	string_value = value;

	std::ostringstream out;
	out << string_value;
	this->value = out.str();
}

template<typename Type>
StringConverterHelper<Type>::operator std::string(void) const {
	return value;
}

template<typename Type>
std::string StringConverterHelper<Type>::toString(void) const {
	return value;
}

STRING_CONVERTER_HELPER_FOR_STRING_DEFINITION(const char*);
STRING_CONVERTER_HELPER_FOR_STRING_DEFINITION(std::string);

}
}
#endif
