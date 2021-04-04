#include "Car.h"



namespace sdds {
	Car::Car() : Maker(""), Condition('n'), Tag('c'), TopSpeed(0) 
	{
	};
	Car::Car(std::istream& file)
	{
		std::string temp;
		file >> temp;
		Maker = temp;
		for (size_t i = 0; i < Maker.size(); i++) {
			if (Maker[i] == ',') {
				Maker.erase(i, 1);
			}
		}
		file >> temp;
		if (temp == ",") {
			temp = "";
			file >> temp;
		}
		Condition = temp[0];
		file >> temp;
		if (temp == ",") {
			temp = "";
			file >> temp;
		}
		TopSpeed = std::stoi(temp);
	}

	std::string Car::condition() const
	{
		switch (Condition)
		{
		case 'n':
			return "new";
		case 'b':
			return "broken";
		case 'u':
			return "used";
		default:
			return "";
		}

	}

	void Car::display(std::ostream& out) const

	{
		out << "| ";
		std::cout << std::right << std::setw(10);
		out << Maker << " | ";
		std::cout << std::setw(6)<< std::left;
		out << condition() << " | ";
		std::cout << std::setw(6)<< std::setprecision(2) << std::fixed;
		out << TopSpeed << " |" << std::endl;

	}
	Car::~Car()
	{
	}



}