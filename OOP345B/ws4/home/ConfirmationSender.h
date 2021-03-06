#pragma once
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <ostream>
#include "Reservation.h"

namespace sdds
{
	// sends confirmations for every reservation.
	// The system is used by many restaurants.
	class ConfirmationSender
	{
		const sdds::Reservation** m_reservations = nullptr;
		size_t m_cnt = 0u;
	public:
		ConfirmationSender() {}
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&&) noexcept;

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res);
	};
}
#endif