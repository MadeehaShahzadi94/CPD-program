#include "Reservation.h"
#include <iomanip>
using namespace std;
namespace sdds{
void Reservation::trim(std::string & str) const
{
	size_t i = 0u;
	for (i = 0u; i < str.length() && str[i] == ' '; ++i);
	str = str.substr(i);

	for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
	str = str.substr(0, i);
}
Reservation::Reservation()
{
}

Reservation::Reservation(const std::string & res)
{
	//for reservation id
	//string point 0 for the string start position
	size_t poss = 0;
	//search for : and stop there
	size_t posE = res.find(':');
	//remove the space
	this->trim(res_id = res.substr(poss, posE - poss));

	//for the reservation name
	poss = posE + 1;
	posE = res.find(',', poss);
	this->trim(name_res = res.substr(poss, posE - poss));

	//for the email
	poss = posE + 1;
	posE = res.find(',', poss);
	this->trim(email = res.substr(poss, posE - poss));

	//number of people in party
	poss = posE + 1;
	posE = res.find(',', poss);
	numOfPeople = std::stoi(res.substr(poss, posE - poss));

	//days
	poss = posE + 1;
	posE = res.find(',', poss);
	m_day = std::stoi(res.substr(poss, posE - poss));

	//hours
	poss = posE + 1;
	posE = res.find(',', poss);
	m_hour = std::stoi(res.substr(poss, posE - poss));

}

std::ostream & operator<<(std::ostream & out, const Reservation & res)
{
	// TODO: insert return statement here
	std::string mail = "<" + res.email + ">";
	out << "Reservation " << res.res_id << ": " << std::setw(10) << std::right << res.name_res << "  " << std::setw(20) << std::left << mail << std::right;
	if (6 <= res.m_hour && res.m_hour <= 9)
		out << "    Breakfast ";
	else if (11 <= res.m_hour && res.m_hour <= 15)
		out << "    Lunch ";
	else if (17 <= res.m_hour && res.m_hour <= 21)
		out << "    Dinner ";
	else
		out << "    Drinks ";
	out << "on day " << res.m_day << " @ " << res.m_hour
		<< ":00 for " << res.numOfPeople << " people.\n";

	return out;

}
}