

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
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

	};





}
#endif