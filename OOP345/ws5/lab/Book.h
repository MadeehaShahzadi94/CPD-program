#ifndef _SDDS_BOOK_H__
#define _SDDS_BOOK_H__

#include <iostream>

namespace sdds {
	class Book {
		std::string copy{ "" };
		std::string m_author;
		std::string m_title;
		std::string m_countryPublication;
		unsigned int m_yearPublication = 0;
		double m_priceBook = 0.00;
		std::string m_summaryBook;
		//void trim(std::string& str) const;
	public:
		Book(); // default constructor
		const std::string& title() const {
			return m_title;
		}
		//: a query that returns the title of the book
		const std::string& country() const {
			return m_countryPublication;
		}
		//: a query that returns the publication country
		const size_t& year() const {
			return m_yearPublication;
		}
		//: a query that returns the publication year
		double& price() {
			return m_priceBook;
		}
		// : a function that returns the price by referene, allowing you to update the price
		Book(const std::string& strBook); // recv book string and store in instance's attributes

		//void display(std::ostream& os) const;

		~Book();
		friend std::ostream& operator<< (std::ostream&, const Book&);
	};

	
}
#endif // !_SDDS_BOOK_H__
