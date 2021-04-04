/* Name:Madeeha Shahzadi
 Seneca Student ID:130638182
 Seneca email:mshahzadi1@mysenecac.on.ca
 Date of completion: March 15,2020

I confirm that the content of this file is created by me,
   with the exception of the parts provided to me by my professor.*/
   /*************************************************************************/
#pragma once
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include <iomanip>
#include <string>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle
	{
		std::string maker;
		std::string m_condition;
		//char Tag;
		double m_topSpeed;
	protected:
		std::string& trim(std::string& token);
	
	public:
		
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		
	};





}
#endif