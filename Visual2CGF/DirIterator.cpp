// --------------------------------------------------------------------------
// NAME      : DirIterator.cpp
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/3/2017 3:10:16 PM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#include "DirIterator.h"
#include <winerror.h>
#include <algorithm>

#define BOOST_FILESYSTEM_NO_DEPRECATED

using namespace boost;


DirIterator::DirIterator() {
}

DirIterator::~DirIterator() {
}

int DirIterator::find_files(std::string ext, filesystem::path root, std::vector<std::string>& vec, bool subdirs) {

	// Check that dir root exists and is actually a directory, and not a file
	if (!filesystem::exists(root)) return ERROR_BAD_CURRENT_DIRECTORY;
	if (!filesystem::is_directory(root)) return ERROR_FILE_INVALID;

	if (subdirs) {
		return find_recursive(ext, root, vec);
	}
	else {
		return find_in_current(ext, root, vec);
	}
}

int DirIterator::find_in_current(std::string ext, boost::filesystem::path root, std::vector<std::string> & vec) {
	//define past-the-end iterator (default construction)
	filesystem::directory_iterator end;

	for (filesystem::directory_iterator it(root); it != end; ++it) {
		if (it->path().extension() == ext) {
			vec.push_back(it->path().string());
		}
	}
	return NO_ERROR;
}

int DirIterator::find_recursive(std::string ext, boost::filesystem::path root, std::vector<std::string> & vec) {

	filesystem::recursive_directory_iterator end;

	for (filesystem::recursive_directory_iterator it(root); it != end; ++it) {
		std::string item = it->path().filename().string();
		//Iterate any (sub)directory
		if (filesystem::is_directory(it->path())) {
			find_recursive(ext, it->path(), vec);
		}
		//push files to the vector
		else if (it->path().extension() == ext) {
			if (std::find(vec.begin(), vec.end(), it->path().string()) == vec.end()) {
				vec.push_back(it->path().string());
			}
		}
	}
	return NO_ERROR;
}




// End of file