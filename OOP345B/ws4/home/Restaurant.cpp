#include "Restaurant.h"

namespace sdds
{
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		this->m_res = new Reservation[cnt];
		this->m_cnt = cnt;
		for (auto i = 0u; i < cnt; ++i)
			this->m_res[i] = *reservations[i];
	}
	Restaurant::Restaurant(const Restaurant& other)
	{
		*this = other;
	}
	Restaurant& Restaurant::operator=(const Restaurant& other)
	{
		if (this != &other)
		{
			m_day = other.m_day;
			m_cnt = other.m_cnt;

			delete[] this->m_res;
			this->m_res = new Reservation[m_cnt];
			for (auto i = 0u; i < m_cnt; ++i)
				this->m_res[i] = other.m_res[i];
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& other) noexcept
	{
		*this = std::move(other);
	}
	Restaurant& Restaurant::operator=(Restaurant&& other) noexcept
	{
		if (this != &other)
		{
			m_day = other.m_day;
			m_cnt = other.m_cnt;

			delete[] this->m_res;
			this->m_res = other.m_res;
			other.m_day = 0;
			other.m_cnt = 0;
			other.m_res = nullptr;
		}
		return *this;
	}
	Restaurant::~Restaurant()
	{
		delete[] m_res;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		os << "--------------------------\n";
		os << "Fancy Restaurant\n";
		os << "--------------------------\n";
		if (res.m_cnt == 0)
			os << "The object is empty!\n";
		for (auto i = 0u; i < res.m_cnt; ++i)
			os << res.m_res[i];
		os << "--------------------------\n";
		return os;
	}
}