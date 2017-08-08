// --------------------------------------------------------------------------
// NAME      : Node.h
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/8/2017 10:23:00 AM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#ifndef _Node_H
#define _Node_H


// Includes -----------------------------------------------------------------
#include <mgapiall.h>
#include <string>
#include <vector>

// Macros -------------------------------------------------------------------

namespace OpenFlight
{

    class Node
    {
    protected:
        Node(Node *parent);
        Node(mgrec *rec, Node *parent);
        ~Node();
        void setRecord(mgrec *rec);

    public:
        inline const Node* parent() const { return mParent; }
        inline void parent(Node* parent) { mParent = parent; }
        inline const std::vector<Node*> children() const { return mChildren; }
        inline const std::string name() const { return mName; }
        inline const FltRecordTableDefs type() const { return mType; }
        inline const std::string filepath() const { return mFilePath; }
        inline const std::string filename() const { return mFileName; }
        void checkCAEstd(void(*msgCallback)(std::string));
        const std::string nodepath() const;
        void nodepath(std::string &) const;

    private:
        void initChildren();

    private:
        Node *mParent;
        std::vector<Node*> mChildren;
        mgrec *mRec;
        std::string mName;
        std::string mFilePath;
        std::string mFileName;
        FltRecordTableDefs mType;

    };

}
#endif // !_Node_H
