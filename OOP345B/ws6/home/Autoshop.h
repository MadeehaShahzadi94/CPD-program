/* Name:Madeeha Shahzadi
 Seneca Student ID:130638182
 Seneca email:mshahzadi1@mysenecac.on.ca
 Date of completion: March 15,2020

I confirm that the content of this file is created by me,
   with the exception of the parts provided to me by my professor.*/
   /*************************************************************************/

#pragma once
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include <iostream>
#include "Vehicle.h"

namespace sdds {

	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop() = default;
		virtual ~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		

		//Algorithm at home
		template<typename T>
		void select(T condition, std::list<const Vehicle*>& vehicles)
		{
			for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
			{
				if (condition(*it))
					vehicles.push_back(*it);
			}
		}
	};
	
	


}
#endif