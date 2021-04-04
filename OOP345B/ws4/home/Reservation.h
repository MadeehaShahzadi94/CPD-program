#pragma once
#ifndef SDDS_RESERVATION_H
# define SDDS_RESERVATION_H

#include <string>
namespace sdds {
	class Reservation {
		//reservation id: an array of characters
		std::string res_id = "";
		//the name on the reservation
		std::string name_res = "";
			//the email that can be used to send the confirmation that the reservation can be honored or not
		std::string email = "";
			//the number of people in the party
		size_t numOfPeople = 0;
			//the day when the party is expected to come(for simplicity, the day is an integer between 1 and 31)
		size_t m_day = 0;
			//the hour when the party is expected to come(for simplicity, the hour is an integer between 1 and 24)
		size_t m_hour = 0;
		void trim(std::string& str) const;
	public:
		//a default constructor
		Reservation();
		//one arugument constructor
		Reservation(const std::string& res);
		// helper function
		friend std::ostream& operator<<(std::ostream& out, const Reservation& res);
	
	};

}
#endif // !1

