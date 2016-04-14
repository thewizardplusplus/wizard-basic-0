#ifndef VERSION_H
#define VERSION_H

#include "Formatter.h"

namespace thewizard {
namespace utils {

template<unsigned int MAJOR_VERSION_VALUE, unsigned int MINOR_VERSION_VALUE>
class Version {
public:
	static const unsigned int MAJOR_VERSION =  MAJOR_VERSION_VALUE;
	static const unsigned int MINOR_VERSION =  MINOR_VERSION_VALUE;
	static const unsigned int PACKED_VERSION = (MAJOR_VERSION << 8) +
		MINOR_VERSION;
	static const std::string  STRING_VERSION_FORMAT;
	static const std::string  STRING_VERSION;
};

template<unsigned int MAJOR_VERSION_VALUE, unsigned int MINOR_VERSION_VALUE>
const std::string Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE>
	::STRING_VERSION_FORMAT = "%0%.%1%";

template<unsigned int MAJOR_VERSION_VALUE, unsigned int MINOR_VERSION_VALUE>
const std::string Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE>
	::STRING_VERSION = utils::Formatter(Version<MAJOR_VERSION_VALUE,
	MINOR_VERSION_VALUE>::STRING_VERSION_FORMAT) << Version<MAJOR_VERSION_VALUE,
	MINOR_VERSION_VALUE>::MAJOR_VERSION << Version<MAJOR_VERSION_VALUE,
	MINOR_VERSION_VALUE>::MINOR_VERSION;
}
}
#endif
