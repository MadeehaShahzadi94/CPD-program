#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <utility>
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender: public Reservation {
		Reservation** reservation{ nullptr };
		std::size_t count{ 0 };
	public:
	public:
		/*default constructor*/
		ConfirmationSender();
		/*copy constructor*/
		ConfirmationSender(const ConfirmationSender&);
		/*move constructor*/
		ConfirmationSender(ConfirmationSender&&);
		/*assignment constructor*/
		ConfirmationSender& operator=(const ConfirmationSender&);
		/*move assignment constructor*/
		ConfirmationSender& operator=(ConfirmationSender&&);
		/*adding operator*/
		ConfirmationSender& operator+=(const Reservation&);
		/*sub operator*/
		ConfirmationSender& operator-=(const Reservation&);
		/*destructor*/
		~ConfirmationSender();
		void display(std::ostream&)const;
		friend  std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
	};
}








#endif