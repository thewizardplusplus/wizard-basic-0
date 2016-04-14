#ifndef VERSION_H
#define VERSION_H

#include <QtCore/QString>

namespace thewizard {
namespace utils {

template<unsigned char MAJOR_VERSION_VALUE, unsigned char MINOR_VERSION_VALUE,
	unsigned char PATCH_VERSION_VALUE = 0>
class Version {
public:
	static const unsigned char MAJOR_VERSION =         MAJOR_VERSION_VALUE;
	static const unsigned char MINOR_VERSION =         MINOR_VERSION_VALUE;
	static const unsigned char PATCH_VERSION =         PATCH_VERSION_VALUE;
	static const unsigned int  PACKED_VERSION =        (static_cast<
		unsigned int>(MAJOR_VERSION) << 16) + (static_cast<unsigned int>(
		MINOR_VERSION) << 8) + PATCH_VERSION;
	static const QString       STRING_VERSION_FORMAT;
	static const QString       STRING_VERSION;

	static bool checkVersion(unsigned char major_version_value);
	static bool checkVersion(unsigned char major_version_value,
		unsigned char minor_version_value);
	static bool checkVersion(unsigned char major_version_value,
		unsigned char minor_version_value, unsigned char patch_version_value);
};

template<unsigned char MAJOR_VERSION_VALUE, unsigned char MINOR_VERSION_VALUE,
	unsigned char PATCH_VERSION_VALUE>
const QString Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE,
	PATCH_VERSION_VALUE>::STRING_VERSION_FORMAT = "%1.%2.%3";

template<unsigned char MAJOR_VERSION_VALUE, unsigned char MINOR_VERSION_VALUE,
	unsigned char PATCH_VERSION_VALUE>
const QString Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE,
	PATCH_VERSION_VALUE>::STRING_VERSION = Version<MAJOR_VERSION_VALUE,
	MINOR_VERSION_VALUE, PATCH_VERSION_VALUE>::STRING_VERSION_FORMAT.arg(
	Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE, PATCH_VERSION_VALUE>
	::MAJOR_VERSION).arg(Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE,
	PATCH_VERSION_VALUE>::MINOR_VERSION).arg(Version<MAJOR_VERSION_VALUE,
	MINOR_VERSION_VALUE, PATCH_VERSION_VALUE>::PATCH_VERSION);

template<unsigned char MAJOR_VERSION_VALUE, unsigned char MINOR_VERSION_VALUE,
	unsigned char PATCH_VERSION_VALUE>
bool Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE, PATCH_VERSION_VALUE>
	::checkVersion(unsigned char major_version_value) {
	return MAJOR_VERSION == major_version_value;
}

template<unsigned char MAJOR_VERSION_VALUE, unsigned char MINOR_VERSION_VALUE,
	unsigned char PATCH_VERSION_VALUE>
bool Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE, PATCH_VERSION_VALUE>
	::checkVersion(unsigned char major_version_value,
	unsigned char minor_version_value)
{
	return MAJOR_VERSION == major_version_value &&
		MINOR_VERSION == minor_version_value;
}

template<unsigned char MAJOR_VERSION_VALUE, unsigned char MINOR_VERSION_VALUE,
	unsigned char PATCH_VERSION_VALUE>
bool Version<MAJOR_VERSION_VALUE, MINOR_VERSION_VALUE, PATCH_VERSION_VALUE>
	::checkVersion(unsigned char major_version_value,
	unsigned char minor_version_value, unsigned char patch_version_value)
{
	return MAJOR_VERSION == major_version_value &&
		MINOR_VERSION == minor_version_value &&
		PATCH_VERSION == patch_version_value;
}

}
}
#endif
