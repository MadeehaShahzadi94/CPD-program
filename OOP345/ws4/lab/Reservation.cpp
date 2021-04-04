#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include <cstring>
#include <sstream>
#include "Reservation.h"

using namespace std;

namespace sdds {
	Reservation::Reservation(){
		m_ID = m_nameReservation = m_email = "";
		m_noPeople = m_day = m_hour = 0;
	}

	Reservation::Reservation(const std::string& m_res) {
		m_fullmsg = m_res;

		while (m_fullmsg.find(" ") != std::string::npos) {
			auto pos = m_fullmsg.find(" ");
			m_fullmsg.erase(pos, 1);
		}

		// to get ID
		std::size_t posID = m_fullmsg.find(":");  // position of ":" in m_fullmsg
		std::string strID = m_fullmsg.substr(0, posID);     // from start till ":"

		m_ID = strID;

		m_fullmsg.erase(0,posID); // delete m_ID from m_fullmsg.erase
		m_fullmsg.erase(0, 1);

		// to get Name
		std::size_t posName = m_fullmsg.find(",");  // position of "," in m_fullmsg
		std::string strName = m_fullmsg.substr(0, posName);     // from start till ":"

		m_nameReservation = strName;

		m_fullmsg.erase(0, posName+1); // delete NAMES from file
		
		// to get EMAIL
		std::size_t posEmail = m_fullmsg.find(",");  // position of "," in m_fullmsg
		std::string strEmail = m_fullmsg.substr(0, posEmail);     // from start till ":"

		m_email = strEmail;

		m_fullmsg.erase(0, posEmail); // delete 
		/*
		// to get PARTY NUMBER
		std::size_t posNumbr = m_fullmsg.find(",");  // position of "," in m_fullmsg
		std::string strNumbr = m_fullmsg.substr(0, posNumbr);     // from start till ":"
		stringstream geek1(strNumbr);

		geek1 >> m_noPeople;

		//m_fullmsg.erase(0, posNumbr); // delete 

		// to get Day
		std::size_t posDay = m_fullmsg.find(",");  // position of "," in m_fullmsg
		std::string strDay = m_fullmsg.substr(0, posDay);     // from start till ":"
		stringstream geek2(strDay);

		geek2 >> m_day;

		//m_fullmsg.erase(0, posDay); // delete 

		// to get Time

		std::string strTime = m_fullmsg.substr(0);     // from start till ":"
		stringstream geek3(strTime);

		geek3 >> m_hour;
		*/
	}

	void Reservation::display(std::ostream& os) const {
		if (this->m_hour >= 6 && m_hour <= 9) {
			os << "Reservation " << m_ID << ": " << m_nameReservation << " <" << m_email << "> " << "Breakfast on day " << m_day << " @ " << m_hour << " : 00 for " << m_noPeople << " people." << std::endl;
		}

		else if (m_hour >= 11 && m_hour <= 15) {
			os << "Reservation " << m_ID << ": " << m_nameReservation << " <" << m_email << "> " << "Lunch on day " << m_day << " @ " << m_hour << " : 00 for " << m_noPeople << " people." << std::endl;
		}

		else if (m_hour >= 17 && m_hour <= 21) {
			os << "Reservation " << m_ID << ": " << m_nameReservation << " <" << m_email << "> " << "Dinner on day " << m_day << " @ " << m_hour << " : 00 for " << m_noPeople << " people." << std::endl;
		}

		else {
			os << "Reservation " << m_ID << ": " << m_nameReservation << " <" << m_email << "> " << "Drink on day " << m_day << " @ " << m_hour << " : 00 for " << m_noPeople << " people." << std::endl;
		}
	}

	std::ostream& operator<< (std::ostream& os, const Reservation& src) {
		src.display(os);
		return os;
	}
}