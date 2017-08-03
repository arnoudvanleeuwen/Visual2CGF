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

private:
	const std::string file;
};


#endif // !_MovingModel_H
