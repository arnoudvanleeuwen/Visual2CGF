// --------------------------------------------------------------------------
// NAME      : MovingModel.cpp
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/3/2017 5:02:30 PM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#include "MovingModel.h"


MovingModel::MovingModel(const std::string filename)
	: file(filename.c_str()) {
	//clean initial msgBuf value
	memset(msgBuf, 0, sizeof(msgBuf));
	if (!(db = mgOpenDb(file))) {
		storeLastError();
	}

}

MovingModel::~MovingModel() {

}

void MovingModel::storeLastError() {
	mgGetLastError(msgBuf, strlen(msgBuf));
}


// End of file