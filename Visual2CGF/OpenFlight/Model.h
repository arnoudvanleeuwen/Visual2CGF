// --------------------------------------------------------------------------
// NAME      : Model.h
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/8/2017 11:07:17 AM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#ifndef _Model_H
#define _Model_H


// Includes -----------------------------------------------------------------
#include "Node.h"

#ifdef _MSC_VER
#include <ShlObj.h>
#pragma comment(lib, "Shell32.lib")
#endif // _MSC_VER

// Macros -------------------------------------------------------------------

namespace OpenFlight
{

    class Model : public Node
    {
    public:
        Model(std::string filepath);
        ~Model();
        void openDirectory() const;
    };

}

#endif // !_Model_H
