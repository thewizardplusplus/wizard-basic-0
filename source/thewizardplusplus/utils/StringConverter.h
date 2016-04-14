#ifndef STRINGCONVERTER_H
#define STRINGCONVERTER_H

#include "StringConverterHelper.h"

namespace thewizard {
namespace utils {

class StringConverter {
public:
	template<typename Type>
	inline static StringConverterHelper<Type> convert(Type value);
};

template<typename Type>
StringConverterHelper<Type> StringConverter::convert(Type value) {
	return StringConverterHelper<Type>(value);
}

}
}
#endif
