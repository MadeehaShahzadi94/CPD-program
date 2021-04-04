#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_MOVIE_H

#define SDDS_MOVIE_H



#include <iostream>

#include <iomanip>

#include <string>



namespace sdds

{

	class Movie

	{

	private:

		std::string m_title = "";

		std::string m_description = "";

		size_t m_year = 0u;



		void trim(std::string& str) const; // const because not changing state of object

	public:

		Movie() {};

		Movie(const std::string& strMovie);

		const std::string& title() const { return m_title; };



		// template function

		//

		// - Will receive any type of function of type SpellChecker

		// - In SpellChecker we overloaded () operator, so in the body we are passing the description to the function

		template<typename T>

		void fixSpelling(T spellChecker) {

			spellChecker(m_title);

			spellChecker(m_description);

		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& m);

	};

}



#endif // !SDDS_MOVIE_H