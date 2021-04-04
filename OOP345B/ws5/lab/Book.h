// Name: Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@mysenecac.on.ca
// Date of completion:Feb 12,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <ostream>
#include<string>

namespace sdds {
	class Book {
		//author
		std::string m_author;
		//title
		std::string m_title;
		//the country of publication
		std::string m_country;
		// the year of publication
		size_t m_yearOFPub =0;
		// the price of the book
		double m_price = 0;
		//the summary of the book
		std::string m_description;
		// trim function
		void trim(std::string& str) const;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		virtual ~Book();
		//friend helper function
		friend std::ostream& operator<<(std::ostream& out, const Book& theBook);

	};
}
#endif // !SDDS_BOOK_H
