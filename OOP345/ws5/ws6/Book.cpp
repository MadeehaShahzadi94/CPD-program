#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"



namespace sdds {



	// Take out whitespace of recieved string

	//

	void Book::trim(std::string& str) const {

		size_t i = 0u;

		// start at 0 and if that index is a whitespace then move to the next index

		for (i = 0u; i < str.length() && str[i] == ' '; ++i);

		// i will be at the position with the first non whitespace then substr from that pos to the end

		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i-1] == ' '; --i);

		str = str.substr(0, i);

	}

	

	// Default Constructor

	//

	Book::Book() {

		m_author = "";

		m_title = "";

		m_country = "";

		m_description = "";

		m_price = 0.0;

		m_year = 0u;

	}



	// Book(const std::string strBook)

	//

	Book::Book(const std::string strBook) {

		size_t posS = 0;

		size_t posE = strBook.find(',');

		this->trim(m_author = strBook.substr(posS, posE));



		posS = posE + 1;

		posE = strBook.find(',', posS);

		this->trim(m_title = strBook.substr(posS, posE - posS));



		posS = posE + 1;

		posE = strBook.find(',', posS);

		this->trim(m_country = strBook.substr(posS, posE - posS));



		posS = posE + 1;

		posE = strBook.find(',', posS);

		this->m_price = std::stod(strBook.substr(posS, posE - posS));



		posS = posE + 1;

		posE = strBook.find(',', posS);

		this->m_year = std::stoi(strBook.substr(posS, posE - posS));



		posS = posE + 1;

		this->trim(m_description = strBook.substr(posS));

	}



	// operator<< overload

	//

	std::ostream& operator<<(std::ostream& os, const Book& b) {

		os << std::setw(20) << b.m_author << " | " << std::setw(22) << b.m_title << " | " << std::setw(5) << b.m_country

			<< " | " << std::setw(4) << b.m_year << " | " << std::fixed << std::setw(6) << std::setprecision(2) << b.m_price << " | " << b.m_description << std::endl;

		return os;

	}

}


