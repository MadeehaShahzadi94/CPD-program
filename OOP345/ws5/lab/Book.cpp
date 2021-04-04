#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <sstream>
#include "Book.h"
#include <iomanip>

using namespace std;

namespace sdds {

	//trim function
	/*void Book::trim(std::string& str) const {
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr[i];

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}*/
	// default constructor
	Book::Book() :m_author{ " " },
		m_title{ " " },
		m_countryPublication{ " " },
		m_yearPublication{ 0 },
		m_priceBook{ 0 },
		m_summaryBook{ " " }{}

	// receives book as string and store in instance's attributes
	Book::Book(const string& strBook) {
		copy = strBook;
		std::string space(" ");
		std::string comma(",");
		std::string title{ "" };
		//	copy.erase(std::find(copy.begin(), copy.end(), ' ') );
			//copy.erase(remove(copy.begin(), copy.end(), ' '));

		this->m_author = copy.substr(copy.find_first_not_of(" "), copy.find(comma));
		copy.erase(0, copy.find(comma) + 1);
		title = copy.substr(copy.find_first_not_of(" "), copy.find(comma) - copy.find_first_not_of(" "));
		this->m_title = title.substr(title.find_first_not_of(" "), title.find_last_not_of(" ") + 1);
		//std::cout << Title << std::endl;
		copy.erase(0, copy.find(comma) + 1);
		this->m_countryPublication = copy.substr(copy.find_first_not_of(" "), copy.find(comma) - copy.find_first_not_of(" "));
		copy.erase(0, copy.find(comma) + 1);
		this->m_priceBook = std::stod(copy.substr(0, copy.find(comma)));
		copy.erase(0, copy.find(comma) + 1);
		this->m_yearPublication = std::stoi(copy.substr(0, copy.find(comma)));
		copy.erase(0, copy.find(comma) + 1);
		this->m_summaryBook = copy.substr(copy.find_first_not_of(" "), copy.find("\n"));
	}

		ostream& operator<< (ostream & os, const Book & src) {
			os << setw(20) << src.m_author;
			os << " | ";
			os << setw(22) << src.m_title;
			os << " | ";
			os << setw(5) << src.m_countryPublication;
			os << " | ";
			os << setw(4) << src.m_yearPublication;
			os << " | ";
			os << setw(6) << src.m_priceBook;
			os << " | ";
			os << src.m_summaryBook << endl;
			
		}

		Book::~Book() {	}

	}