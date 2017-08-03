// --------------------------------------------------------------------------
// NAME      : Settings.h
// PURPOSE   : Manage the contents of the settings file
// AUTHOR    : leeuwenab
// DATE      : 8/2/2017 3:38:18 PM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#ifndef _Settings_H
#define _Settings_H


// Includes -----------------------------------------------------------------
#include <qstring.h>
#include <pugixml-1.8\pugixml.hpp>

// Macros -------------------------------------------------------------------
#define SETTING_FILE	"settings.xml"
#define SETTING_REPO	"PathToRepo"
#define SETTING_DATA3	"PathToData3"
#define SETTING_DRIVE	"DefaultDrive"


class Settings
{
public:
	Settings();
	~Settings();

	void set_path_to_repo(std::string);
	void set_path_to_data(std::string);
	void set_default_drive(std::string);
	inline bool save() const { return mdoc.save_file(SETTING_FILE); }
	std::string path_to_repo() const;
	std::string path_to_data3() const;
	QString drive_letter() const;

private:
	pugi::xml_document mdoc;
};


#endif // !_Settings_H
