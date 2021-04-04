#define _CRT_SECURE_NO_WARNINGS_
#ifndef _SDDS_RESERVATION_H__
#define _SDDS_RESERVATION_H__
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include <cstring>

namespace sdds {
	class Reservation {
		std::string m_fullmsg;
		std::string m_ID;
		std::string m_nameReservation;
		std::string m_email;
		int m_noPeople = 0;
		int m_day = 0;
		int m_hour = 0;

	public:
		Reservation();

		Reservation(const std::string& m_res);
		void display(std::ostream& os) const;
	};

	std::ostream& operator<< (std::ostream& os, const Reservation& src);

}
#endif // !_SDDS_RESERVATION_H__
