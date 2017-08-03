// --------------------------------------------------------------------------
// NAME      : DirIterator.h
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/3/2017 3:10:16 PM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#ifndef _DirIterator_H
#define _DirIterator_H


// Includes -----------------------------------------------------------------
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

// Macros -------------------------------------------------------------------


class DirIterator
{
public:
	DirIterator();
	~DirIterator();

	int find_files(std::string ext, boost::filesystem::path base, std::vector<std::string> &, bool subdirs);


private:
	int find_in_current(std::string ext, boost::filesystem::path base, std::vector<std::string> &);
	int find_recursive(std::string ext, boost::filesystem::path base, std::vector<std::string> &);
};


#endif // !_DirIterator_H
