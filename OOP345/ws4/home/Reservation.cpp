

#include "Reservation.h"

namespace sdds {
	Reservation::Reservation() {
	}

	Reservation::Reservation(const std::string& me_res) {
		std::string copy = me_res;
		std::string space(" ");
		std::string colon(":");
		std::string comma(",");
		std::string::size_type position;
		while ((position = copy.find(space)) != std::string::npos) {              //remove space
			copy.erase(position, 1);
		}
		this->reservation_id = copy.substr(0, copy.find(colon));
		copy.erase(0, copy.find(colon) + 1);
		this->reservation_name = copy.substr(0, copy.find(comma));
		copy.erase(0, copy.find(comma) + 1);
		this->email = copy.substr(0, copy.find(comma));
		copy.erase(0, copy.find(comma) + 1);
		this->num_people = std::stoi(copy.substr(0, copy.find(comma)));
		copy.erase(0, copy.find(comma) + 1);
		this->day = std::stoi(copy.substr(0, copy.find(comma)));
		copy.erase(0, copy.find(comma) + 1);
		this->hour = std::stoi(copy);
	}

	void Reservation::display(std::ostream & os)const {
		std::string s = "<" + this->email + ">";
		os << "Reservation " << this->reservation_id << ": " << std::right << std::setw(10) << this->reservation_name << "  "
			<< std::left << std::setw(20) << s << "    ";
		if (this->hour >= 6 && this->hour <= 9) {
			os << "Breakfast";
		}
		else if (this->hour >= 11 && this->hour <= 15) {
			os << "Lunch";
		}
		else if (this->hour >= 17 && this->hour <= 21) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}
		os << " on day " << this->day << " @ " << this->hour << ":00 for " << this->num_people << " people." << std::endl;
	}

	std::ostream& operator<<(std::ostream & os, const Reservation & resv) {
		resv.display(os);
		return os;
	}

	std::string Reservation::getID()const {
		return this->reservation_id;
	}

}