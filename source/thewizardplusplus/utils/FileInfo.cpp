#include "FileInfo.h"

using namespace thewizard::utils;

#ifdef OS_WINDOWS
const std::string FileInfo::TYPES_OF_BEGINNING_OF_ABSOLUTE_PATHS =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string FileInfo::SECOND_PART_OF_BEGINNING_OF_ABSOLUTE_PATHS = ":\\";
#endif
#ifdef OS_LINUX
const char        FileInfo::PATH_SEPARATOR =                             '/';
#elif defined(OS_WINDOWS)
const char        FileInfo::PATH_SEPARATOR =                             '\\';
#endif
const char        FileInfo::EXTENSION_SEPARATOR =                        '.';

bool FileInfo::isAbsolutePath(const std::string& file_path) {
	bool absolute_path = false;
	#ifdef OS_LINUX
	if (file_path.length() > 0 && file_path[0] == PATH_SEPARATOR) {
		absolute_path = true;
	}
	#elif defined(OS_WINDOWS)
	std::string::const_iterator i = TYPES_OF_BEGINNING_OF_ABSOLUTE_PATHS
		.begin();
	for (; i != TYPES_OF_BEGINNING_OF_ABSOLUTE_PATHS.end(); ++i) {
		if (file_path[0] == *i) {
			absolute_path = true;
			break;
		}
	}
	if (absolute_path && file_path.substr(1, 2) !=
		SECOND_PART_OF_BEGINNING_OF_ABSOLUTE_PATHS)
	{
		absolute_path = false;
	}
	#endif
	return absolute_path;
}

FileInfo::FileInfo(const std::string& absolute_file_path) :
	absolute_file_path(absolute_file_path)
{}

std::string FileInfo::getAbsoluteFilePath(void) const {
	return absolute_file_path;
}

void FileInfo::setAbsoluteFilePath(const std::string& absolute_file_path) {
	this->absolute_file_path = absolute_file_path;

	absolute_path.clear();
	filename.clear();
	file_extension.clear();
}

std::string FileInfo::getAbsolutePath(void) {
	if (absolute_path.length() == 0) {
		size_t separator_index = absolute_file_path.rfind(PATH_SEPARATOR);
		if (separator_index != std::string::npos) {
			absolute_path = absolute_file_path.substr(0, separator_index + 1);
		}
	}

	return absolute_path;
}

std::string FileInfo::getFilename(void) {
	if (filename.length() == 0) {
		size_t separator_index = absolute_file_path.rfind(PATH_SEPARATOR);
		if (separator_index != std::string::npos) {
			filename = absolute_file_path.substr(separator_index + 1,
				absolute_file_path.length() - separator_index - 1);
		} else {
			filename = absolute_file_path;
		}
	}

	return filename;
}

std::string FileInfo::getFileExtension(void) {
	if (file_extension.length() == 0) {
		size_t filename_separator_index = absolute_file_path.rfind(
			PATH_SEPARATOR);
		size_t extension_separator_index = absolute_file_path.rfind(
			EXTENSION_SEPARATOR);
		if (extension_separator_index != std::string::npos &&
			((filename_separator_index != std::string::npos &&
			extension_separator_index > filename_separator_index) ||
			filename_separator_index == std::string::npos))
		{
			file_extension = absolute_file_path.substr(extension_separator_index
				+ 1, absolute_file_path.length() - extension_separator_index -
				1);
		}
	}

	return file_extension;
}
