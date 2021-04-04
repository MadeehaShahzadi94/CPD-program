

//#define _CRT_SECURE_NO_WARNINGS_
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
		std::string reservation_id{ "" };
		std::string reservation_name{ "" };
		std::string email{ "" };
		unsigned num_people{ 0 };
		unsigned day = { 0 };
		unsigned hour = { 0 };

	public:
		Reservation();
		Reservation(const std::string&);
		void display(std::ostream&)const;
		std::string getID()const;
		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
}

#endif