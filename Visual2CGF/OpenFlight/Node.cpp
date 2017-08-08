// --------------------------------------------------------------------------
// NAME      : Node.cpp
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/8/2017 10:23:00 AM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#include "Node.h"
#include <sstream>

#ifdef _MSC_VER
#define STD_SEPERATOR       "\\"
#define NON_STD_SEPERATOR   "/"
#else
#define STD_SEPERATOR       "/"
#define NON_STD_SEPERATOR   "\\"
#endif // _MSC_VER



OpenFlight::Node::Node(Node * parent)
    : mParent(parent), mChildren(), mRec(), mName(), mType(), mFilePath() {
}

OpenFlight::Node::Node(mgrec * rec, Node * parent)
    : mParent(parent), mChildren(), mRec(rec), mName(mgGetName(rec)), mType(static_cast<FltRecordTableDefs>(mgGetCode(rec))), mFilePath() {
    mFilePath = mgRec2Filename(mRec);
    size_t pos;
    while ( (pos = mFilePath.find(NON_STD_SEPERATOR)) != std::string::npos ) {
        mFilePath.replace(pos, 1, STD_SEPERATOR);
    }
    mFileName = mFilePath.substr(mFilePath.find_last_of(STD_SEPERATOR) + 1, mFilePath.length() - mFilePath.find_last_of(STD_SEPERATOR) - 1);
    initChildren();
}

OpenFlight::Node::~Node() {
}

void OpenFlight::Node::setRecord(mgrec * rec) {
    mRec = rec;
    mName = mgGetName(mRec);
    mType = static_cast<FltRecordTableDefs>(mgGetCode(mRec));
    mFilePath = mgRec2Filename(mRec);
    size_t pos;
    while ( (pos = mFilePath.find(NON_STD_SEPERATOR)) != std::string::npos ) {
        mFilePath.replace(pos, 1, STD_SEPERATOR);
    }
    mFileName = mFilePath.substr(mFilePath.find_last_of(STD_SEPERATOR) + 1, mFilePath.length() - mFilePath.find_last_of(STD_SEPERATOR) - 1);
    initChildren();
}

void OpenFlight::Node::checkCAEstd(void(*msgCallback)(std::string)) {
    // mRec must be initialised before using this function
    if ( !mRec ) {
        std::stringstream ss;
        ss << __FUNCTION__ << ": node not initialized, cannot check CAE standard";
        msgCallback(ss.str());
        return;
    }

    // confirm node type
    switch ( mType ) {
    case eFltPolygon:
        break;
    case eFltXref:
        break;
    case eFltLightPoint:
        break;
    case eFltSwitch:
        break;
    case eFltLod:
        break;
    case eFltObject:
        break;
    case eFltGroup:
        break;
    default:
        std::stringstream ss;
        ss << "No rules defined for node: " << name() << " of type '" << type() << ". Node will not be checked";
        msgCallback(ss.str());
        break;
    }
}

const std::string OpenFlight::Node::nodepath() const {
    std::stringstream ss;
    Node *p;
    while ( (p = mParent) != NULL ) {
        const  std::string tmp = ss.str();
        ss.seekp(0);
        ss << name() << "::" << tmp;
    }
    return ss.str();
}

void OpenFlight::Node::nodepath(std::string & s) const {
    s = nodepath();
}

void OpenFlight::Node::initChildren() {
    mgrec * ch = MG_NULL;
    if ( (ch = mgGetChild(mRec)) != MG_NULL ) {
        mChildren.push_back(new Node(ch, this));
        while ( (ch = mgGetNext(ch)) != MG_NULL ) {
            mChildren.push_back(new Node(ch, this));
        }
    }
}


// End of file