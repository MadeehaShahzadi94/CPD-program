// Name: Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@myseneca.on.ca
// Date of completion:16 Feb 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <ostream>
#include <string>

namespace sdds
{
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_description;
		void trim(std::string& str) const;
	public:
		Movie() :m_year{ 0 } {};
		Movie(const std::string strMovie);

		const std::string& title() const { return m_title; };

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& out, const Movie& theMovie);
	};
}
#endif