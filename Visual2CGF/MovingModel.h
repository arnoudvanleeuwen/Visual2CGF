// --------------------------------------------------------------------------
// NAME      : MovingModel.h
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/3/2017 5:02:30 PM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#ifndef _MovingModel_H
#define _MovingModel_H


// Includes -----------------------------------------------------------------
#include <string>
#include "mgapiall.h"

// Macros -------------------------------------------------------------------


class MovingModel
{
public:
	MovingModel(const std::string filename);
	~MovingModel();
	inline std::string last_error() const { return msgBuf; }

private:
	//members
	const char* file;
	mgrec *db;
	char msgBuf[1024];

	//methods
	void storeLastError();
};


#endif // !_MovingModel_H
