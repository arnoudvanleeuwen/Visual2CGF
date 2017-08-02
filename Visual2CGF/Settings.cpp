// --------------------------------------------------------------------------
// NAME      : Settings.cpp
// PURPOSE   : 
// AUTHOR    : leeuwenab
// DATE      : 8/2/2017 3:38:18 PM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// --------------------------------------------------------------------------

#include "Settings.h"


Settings::Settings() {
	//parse settings.xml
	pugi::xml_parse_result res = mdoc.load_file(SETTING_FILE);
	if (!res) {
		auto decl = mdoc.append_child(pugi::node_declaration);
		decl.append_attribute("version") = "1.0";
		decl.append_attribute("encoding") = pugi::encoding_auto;
		auto root = mdoc.append_child("Settings");
		pugi::xml_node datanode = root.append_child(SETTING_DATA3);
		pugi::xml_node reponode = root.append_child(SETTING_REPO);
		datanode.append_child(pugi::node_pcdata).set_value("");
		reponode.append_child(pugi::node_pcdata).set_value("");
		this->save();
	}
}

Settings::~Settings() {
}

void Settings::set_path_to_repo(std::string s) {
	mdoc.document_element().child(SETTING_REPO).text().set(s.c_str());
}

void Settings::set_path_to_data(std::string s) {
	mdoc.document_element().child(SETTING_DATA3).text().set(s.c_str());
}

std::string Settings::path_to_repo() const {
	return std::string(mdoc.document_element().child(SETTING_REPO).child_value());
}

std::string Settings::path_to_data3() const {
	return std::string(mdoc.document_element().child(SETTING_DATA3).child_value());
}


// End of file