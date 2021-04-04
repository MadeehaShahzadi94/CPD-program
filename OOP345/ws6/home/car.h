
#pragma once
#include <iomanip>

#include <string>

#include <fstream>

#include <algorithm>

#include <vector>

#include "Vehicle.h"





namespace sdds {

	class Car : public Vehicle

	{

		std::string Maker;

		char Condition;

		char Tag;

		double TopSpeed;

	public:

		Car();

		Car(std::istream&);

		std::string condition() const;

		double topSpeed() const { return TopSpeed; }

		void display(std::ostream& out) const;

		~Car();

	};





}
