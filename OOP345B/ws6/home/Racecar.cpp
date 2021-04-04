/* Name:Madeeha Shahzadi
 Seneca Student ID:130638182
 Seneca email:mshahzadi1@mysenecac.on.ca
 Date of completion: March 15,2020*/

#include "Racecar.h"
#include <iostream>
#include <string>
namespace sdds {
	sdds::Racecar::Racecar(std::istream& in):Car(in)
	{
		std::string token;
		std::getline(in, token, ',');
		m_booster = std::stod(token);

	}

	void sdds::Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}

	double sdds::Racecar::topSpeed() const
	{
		// call the function car topspeed
		return Car::topSpeed() * (1 + m_booster);;
	}
}
