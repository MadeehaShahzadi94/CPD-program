// Name: Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@myseneca.on.ca
// Date of completion:16 Feb 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iomanip>
#include "Book.h"
using namespace std;
namespace sdds 
{
	void Book::trim(std::string& str) const
	{
		//	remove the spaces
		size_t i;
		for (i = 0u; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);
		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}

	Book::Book() :m_author{ " " }, m_title{ " " }, m_country{ " " }, m_yearOFPub{ 0 }, m_price{ 0 }, m_description{" "}
	{
	}

	const string& Book::title() const
	{
		// TODO: insert return statement here
		return m_title;
	}

	const string& Book::country() const
	{
		// TODO: insert return statement here
		return m_country;
	}

	const size_t& Book::year() const
	{
		// TODO: insert return statement here
		return m_yearOFPub;

	}

	double& Book::price()
	{
		// TODO: insert return statement here
		return m_price;
	}

	Book::Book(const string& strBook)
	{
		size_t posS = 0;
		size_t posE = strBook.find(',');
		this->trim(m_author = strBook.substr(posS, posE - posS));

		posS = posE + 1;
		posE = strBook.find(',', posS);
		this->trim(m_title = strBook.substr(posS, posE - posS));

		posS = posE + 1;
		posE = strBook.find(',', posS);
		this->trim(m_country = strBook.substr(posS, posE - posS));

		posS = posE + 1;
		posE = strBook.find(',', posS);
		m_price = std::stod(strBook.substr(posS, posE - posS));

		posS = posE + 1;
		posE = strBook.find(',', posS);
		m_yearOFPub = std::stoi(strBook.substr(posS, posE - posS));

		posS = posE + 1;
		this->trim(m_description = strBook.substr(posS));

	}

	Book::~Book()
	{
	}

	ostream& operator<<(ostream& out, const Book& theBook)
	{
		// TODO: insert return statement here
		out << std::setw(20) << theBook.m_author << " | "
			<< std::setw(22) << theBook.m_title << " | "
			<< std::setw(5) << theBook.m_country << " | "
			<< std::setw(4) << theBook.m_yearOFPub << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << theBook.m_price << " | "
			<< theBook.m_description << "\n";
		return out;

	}
}