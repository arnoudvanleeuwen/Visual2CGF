// --------------------------------------------------------------------------
// NAME      : NetworkManager.cpp
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/3/2017 9:34:44 AM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#include "NetworkManager.h"
#include "Settings.h"


NetworkManager::NetworkManager(const std::string & drive, const std::string & user, const std::string & pw)
	: m_drive(), m_user(), m_pw() {
	m_drive = const_cast<wchar_t*>(std::wstring(drive.begin(), drive.end()).c_str());
	m_user = const_cast<wchar_t*>(std::wstring(user.begin(), user.end()).c_str());
	m_pw = const_cast<wchar_t*>(std::wstring(pw.begin(), pw.end()).c_str());

	// Configure network connection
	Settings set;
	m_nr = new NETRESOURCE();
	memset(m_nr, 0, sizeof(*m_nr));

	m_nr->dwType = RESOURCETYPE_DISK;
	m_nr->lpRemoteName = m_drive;
	m_nr->lpLocalName = const_cast<wchar_t*>(std::wstring(set.drive_letter().begin(), set.drive_letter().end()).c_str());

	m_status = WNetUseConnection(NULL, m_nr, m_pw, m_user, NULL, NULL, NULL, NULL);
}

NetworkManager::~NetworkManager()
{
	delete m_nr, m_user, m_pw, m_drive;
}

std::string NetworkManager::drive() const {
	std::wstring wdrive(m_drive);
	return std::string(wdrive.begin(), wdrive.end());
}

std::string NetworkManager::user() const {
	std::wstring wusr(m_user);
	return std::string(wusr.begin(), wusr.end());
}

std::string NetworkManager::pw() const {
	std::wstring wpw(m_pw);
	return std::string(wpw.begin(), wpw.end());
}


// End of file