#ifndef VERSION_H
#define VERSION_H

#include "Formatter.h"

namespace thewizardplusplus {
namespace utils {

template<unsigned char MAJOR_VERSION_VALUE,
	unsigned char MINOR_VERSION_VALUE = 0,
	unsigned char PATCH_VERSION_VALUE = 0>
class Version {
public:
	static const unsigned char MAJOR_VERSION =         MAJOR_VERSION_VALUE;
	static const unsigned char MINOR_VERSION =         MINOR_VERSION_VALUE;
	static const unsigned char PATCH_VERSION =         PATCH_VERSION_VALUE;
	static const unsigned int  PACKED_VERSION =        (static_cast<
		unsigned int>(MAJOR_VERSION) << 16) + (static_cast<unsigned int>(
		MINOR_VERSION) << 8) + PATCH_VERSION;
	static const std::string   STRING_VERSION_FORMAT;
	static const std::string   STRING_VERSION;
};

template<unsigned char MAJOR_VERSION_VALUE, unsigned char MINOR_VERSION_VALUE,
	unsigned char PATCH_VERSION_VALUE>
const std::string Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE,
	PATCH_VERSION_VALUE>::STRING_VERSION_FORMAT = "%0%.%1%.%2%";

template<unsigned char MAJOR_VERSION_VALUE, unsigned char MINOR_VERSION_VALUE,
	unsigned char PATCH_VERSION_VALUE>
const std::string Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE,
	PATCH_VERSION_VALUE>::STRING_VERSION = Formatter(Version<
	MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE, PATCH_VERSION_VALUE>::
	STRING_VERSION_FORMAT).setArgument(Version<MAJOR_VERSION_VALUE,
	MINOR_VERSION_VALUE, PATCH_VERSION_VALUE>::MAJOR_VERSION).setArgument(
	Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE, PATCH_VERSION_VALUE>::
	MINOR_VERSION).setArgument(Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE,
	PATCH_VERSION_VALUE>::PATCH_VERSION);

}
}
#endif
