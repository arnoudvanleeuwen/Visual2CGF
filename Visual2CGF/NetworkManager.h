// --------------------------------------------------------------------------
// NAME      : NetworkManager.h
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/3/2017 9:34:44 AM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#ifndef _NetworkManager_H
#define _NetworkManager_H


// Includes -----------------------------------------------------------------
#include <string>
#include <Windows.h>

// Macros -------------------------------------------------------------------


class NetworkManager
{

public:
	NetworkManager(const std::string & drive, const std::string & user, const std::string & pw);
	~NetworkManager();
	std::string drive() const;
	std::string user() const;
	std::string pw() const;
	inline int status() const { return m_status; }

private:
	wchar_t *m_drive, *m_user, *m_pw;
	int m_status;
	NETRESOURCE *m_nr;
};


#endif // !_NetworkManager_H
