#define _CRT_SECURE_NO_WARNINGS_

#ifndef _SDDS_RESTAURANT_H__
#define _SDDS_RESTAURANT_H__


#include <iostream>
#include "Reservation.h"


namespace sdds {
	class Restaurant: public Reservation
	{
		Reservation* reservation{ nullptr };
		std::size_t count{ 0 };
	public:
		/*default constructor*/
		Restaurant();
		/*2 Argument constructor*/
		Restaurant(Reservation* reservations[], std::size_t);
		/*copy constructor*/
		Restaurant(const Restaurant&);
		/*Move constructor*/
		Restaurant(Restaurant&&);
		/*return the size*/
		std::size_t size() const;
		/*Copy Assignment operator*/
		Restaurant& operator=(const Restaurant&);
		/*Move Assignment operator*/
		Restaurant& operator=(Restaurant&&);

		/*Destructor*/
		~Restaurant();
		bool isEmpty()const;
		void display(std::ostream&)const;
		friend std::ostream& operator<<(std::ostream&, const Restaurant&);

	};
	

}
#endif

