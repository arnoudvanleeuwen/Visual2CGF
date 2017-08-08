// --------------------------------------------------------------------------
// NAME      : Model.cpp
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/8/2017 11:07:17 AM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#include "Model.h"
#include <codecvt>


OpenFlight::Model::Model(std::string filepath)
    : Node(NULL) {
    mgrec *db;
    if ( db = mgOpenDb(filepath.c_str()) ) {
        setRecord(db);
    }
}

OpenFlight::Model::~Model() {
}

void OpenFlight::Model::openDirectory() const {
    #ifdef _MSC_VER
    CoInitialize(NULL);
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring ws = converter.from_bytes(filename());
    ITEMIDLIST* pidl = ILCreateFromPath(ws.c_str());
    if ( pidl ) {
        SHOpenFolderAndSelectItems(pidl, NULL, NULL, NULL);
        ILFree(pidl);
    }
    return;
    #endif // _MSC_VER
}

// End of file
