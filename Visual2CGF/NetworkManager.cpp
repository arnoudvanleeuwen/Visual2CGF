// --------------------------------------------------------------------------
// NAME      : NetworkManager.cpp
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/3/2017 9:34:44 AM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#include "NetworkManager.h"
#include "Settings.h"
#include <qstring.h>
#include <winerror.h>


NetworkManager::NetworkManager(wchar_t* drive, wchar_t* user, wchar_t* pw)
	: m_drive(drive), m_user(user), m_pw(pw), m_connected(false) {

	// Configure network connection
	wchar_t letter[3];
	Settings set;
	set.drive_letter().toWCharArray(letter);
	letter[2] = '\0';

	m_nr = new NETRESOURCE();
	memset(m_nr, 0, sizeof(*m_nr));
	m_nr->dwType = RESOURCETYPE_DISK;
	m_nr->lpRemoteName = m_drive;
	m_nr->lpLocalName = letter;
}

NetworkManager::~NetworkManager() {
	disconnect();
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

int NetworkManager::connect() {
	m_status = WNetUseConnection(NULL, m_nr, m_pw, m_user, NULL, NULL, NULL, NULL);
	if(m_status == NO_ERROR) {
		m_connected = true;
	}
	return m_status;
}

int NetworkManager::disconnect() {
	if (m_status = WNetCancelConnectionW(m_drive, true) == NO_ERROR) {
		m_connected = false;
	}
	return m_status;
}


// End of file