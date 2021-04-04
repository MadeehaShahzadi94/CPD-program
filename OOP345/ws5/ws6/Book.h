#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_BOOK_H

#define SDDS_BOOK_H


#include <iostream>

#include <iomanip>

#include <string>



namespace sdds {

	class Book {

	private:

		std::string	m_author;

		std::string m_title;

		std::string m_country;

		std::string m_description;

		double m_price;

		size_t m_year;



		void trim(std::string& str) const; // const because not changing state of object



	public:

		Book();

		Book(const std::string strBook);



		const std::string& title() const { return m_title; }

		const std::string& country() const { return m_country; }

		const size_t& year() const { return m_year; }

		double& price() { return m_price; } // Return by reference to allow updates in price



		// spellChecker could be a lambda function, a function obj, etc.

		// then we will pass the m_description

		template<typename T>

		void fixSpelling(T spellChecker) {

			spellChecker(m_description);

		}



		friend std::ostream& operator<<(std::ostream& os, const Book& b);

	};

}



#endif // !SDDS_BOOK_H

