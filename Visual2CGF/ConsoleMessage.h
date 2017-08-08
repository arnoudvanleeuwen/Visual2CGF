/****************************************************************************
// NAME      : ConsoleMessage.h
// PURPOSE   : Defines all the aspects of a console message:
//	
// AUTHOR    : leeuwenab
// DATE      : 8/4/2017 5:06:33 PM
// COPYRIGHT : NETHERLANDS AEROSPACE CENTRE - NLR  (AOTS)
// **************************************************************************
*/

#ifndef _ConsoleMessage_H
#define _ConsoleMessage_H


// Includes -----------------------------------------------------------------
#include <string>
#include <sstream>
#include <boost/date_time.hpp>

namespace PT = boost::posix_time;

// Macros -------------------------------------------------------------------
#define ICON_INFO		"Resources\\information.png"
#define ICON_WARNING	"Resources\\warning.png"
#define ICON_ERROR		"Resources\\error.png"
#define DELIMITER		" : "
#define MESSAGE_INFO	0
#define MESSAGE_WARNING	1
#define MESSAGE_ERROR	2

class ConsoleMessage
{
public:
	inline static std::string current_time() {
		std::stringstream ss;
		PT::ptime t = PT::second_clock::local_time();
		ss << std::setfill(' ') << std::setw(4) << t.date().year() << "/";
		ss << std::setfill('0') << std::setw(2) << t.date().month().as_number() << "/";
		ss << std::setfill('0') << std::setw(2) << t.date().day() << " ";
		ss << std::setfill('0') << std::setw(2) << t.time_of_day().hours() << ":";
		ss << std::setfill('0') << std::setw(2) << t.time_of_day().minutes() << ":";
		ss << std::setfill('0') << std::setw(2) << t.time_of_day().seconds();
		return ss.str();
	}
	inline ConsoleMessage(std::string text, int msg_type = MESSAGE_INFO) : msg(text), mtype(msg_type){
		now = PT::second_clock::local_time();
	}
	~ConsoleMessage() {}
	inline const std::string text() const { return msg; }
	inline const std::string icon() const {
		switch (mtype) {
		case MESSAGE_INFO:
			return ICON_INFO;
		case MESSAGE_WARNING:
			return ICON_WARNING;
		case MESSAGE_ERROR:
			return ICON_ERROR;
		default:
			return "";
		}
	}
	inline int type() const {
		switch (mtype) {
		case MESSAGE_INFO:
			return MESSAGE_INFO;
		case MESSAGE_WARNING:
			return MESSAGE_WARNING;
		case MESSAGE_ERROR:
			return MESSAGE_ERROR;
		default:
			return -1;
		}
	}
	inline const std::string time() const {
		std::stringstream ss;
		ss << std::setfill(' ') << std::setw(4) << now.date().year() << "/";
		ss << std::setfill('0') << std::setw(2) << now.date().month().as_number() << "/";
		ss << std::setfill('0') << std::setw(2) << now.date().day() << " ";
		ss << std::setfill('0') << std::setw(2) << now.time_of_day().hours() << ":";
		ss << std::setfill('0') << std::setw(2) << now.time_of_day().minutes() << ":";
		ss << std::setfill('0') << std::setw(2) << now.time_of_day().seconds();
		return ss.str();
	}
	inline const std::string deletimiter() const { return DELIMITER; }


private:
	std::string msg;
	PT::ptime now;
	int mtype;


};


#endif // !_ConsoleMessage_H
