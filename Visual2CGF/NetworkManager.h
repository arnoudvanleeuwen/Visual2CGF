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
	NetworkManager(wchar_t* drive, wchar_t* user, wchar_t* pw);
	~NetworkManager();
	std::string drive() const;
	std::string user() const;
	std::string pw() const;
	inline int status() const { return m_status; }
	inline int connected() const { return m_connected; }
	int connect();
	int disconnect();

private:
	wchar_t *m_drive, *m_user, *m_pw;
	int m_status;
	bool m_connected;
	NETRESOURCE *m_nr;
};


#endif // !_NetworkManager_H
