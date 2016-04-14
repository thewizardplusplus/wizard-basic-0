#ifndef FILEINFO_H
#define FILEINFO_H

#include "os.h"
#include <string>

namespace thewizard {
namespace utils {

class FileInfo {
public:
	#ifdef OS_WINDOWS
	static const std::string TYPES_OF_BEGINNING_OF_ABSOLUTE_PATHS;
	static const std::string SECOND_PART_OF_BEGINNING_OF_ABSOLUTE_PATHS;
	#endif
	static const char        PATH_SEPARATOR;
	static const char        EXTENSION_SEPARATOR;

	static bool isAbsolutePath(const std::string& file_path);

	explicit FileInfo(const std::string& absolute_file_path);
	std::string getAbsoluteFilePath(void) const;
	void setAbsoluteFilePath(const std::string& absolute_file_path);
	std::string getAbsolutePath(void);
	std::string getFilename(void);
	std::string getFileExtension(void);

private:
	std::string absolute_file_path;
	std::string absolute_path;
	std::string filename;
	std::string file_extension;
};

}
}
#endif
