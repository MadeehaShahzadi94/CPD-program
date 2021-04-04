#include <vector>
#include <list>
#include <iostream>
#include "Vehicle.h"
#include "Autoshop.h"
#include "Utilities.h"
namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		size_t i = 0;
		out << "--------------------------------" << std::endl <<
			"| Cars in the autoshop!        |" << std::endl <<
			"--------------------------------" << std::endl;
		for (auto it = m_vehicles.rbegin(); it != m_vehicles.rend(); ++it, i++) {
			m_vehicles[i]->display(out);
		}
		out << "--------------------------------" << std::endl;

	}
	Autoshop::~Autoshop()

	{
		while (!m_vehicles.empty())
		{
			delete m_vehicles.back();
			m_vehicles.pop_back();
		}
	}



}