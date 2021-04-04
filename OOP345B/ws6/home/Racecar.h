#pragma once
/* Name:Madeeha Shahzadi
 Seneca Student ID:130638182
 Seneca email:mshahzadi1@mysenecac.on.ca
 Date of completion: March 15,2020

I confirm that the content of this file is created by me,
   with the exception of the parts provided to me by my professor.*/
   /*************************************************************************/

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include <string>
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif