#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <ostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant {
		// dynamically allocated
	Reservation* m_res = nullptr;
	size_t m_cnt = 0u;
	size_t m_day = 0u;
	public:
		Restaurant(Reservation* reservations[], size_t cnt);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
		//special functions
		//1. Copy Constructor:
		Restaurant(const Restaurant& other);
		//2. Copy Assignment Constructor
		Restaurant& operator=(const Restaurant& other);
		//3. Move Constructor:
		Restaurant(Restaurant&& other) noexcept;
		//4. Move assignment Constructor
		Restaurant& operator=(Restaurant&& other) noexcept;
		//5.Destructor
		virtual ~Restaurant();
	};
	
}

#endif