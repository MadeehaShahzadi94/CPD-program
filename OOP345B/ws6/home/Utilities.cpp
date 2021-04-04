/* Name:Madeeha Shahzadi
 Seneca Student ID:130638182
 Seneca email:mshahzadi1@mysenecac.on.ca
 Date of completion: March 15,2020

I confirm that the content of this file is created by me,
   with the exception of the parts provided to me by my professor.*/
   /*************************************************************************/
#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {

		std::string line;
		char type = '\0';
		char delim = '\0';

		std::getline(in, line);
		std::stringstream obj(line);
		obj >> type >> delim;

		if (obj)
		{
			switch (type)
			{
			case 'c':
			case 'C':
				return new Car(obj);
				break;
			case 'r':
			case 'R':
				return new Racecar(obj);
				break;
			default:
				throw type;
				break;
			}
		}
		return nullptr;
	}



}