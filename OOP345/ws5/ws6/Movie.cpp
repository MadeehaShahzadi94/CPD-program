#include "Movie.h"



namespace sdds 

{

	// Take out whitespace of recieved string

	//

	void Movie::trim(std::string& str) const {

		size_t i = 0u;

		// start at 0 and if that index is a whitespace then move to the next index

		for (i = 0u; i < str.length() && str[i] == ' '; ++i);



		// i will be at the position with the first non whitespace then substr from that pos to the end

		str = str.substr(i);



		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);

		str = str.substr(0, i);

	}



	// Movie(const std::string& strMovie)

	//

	Movie::Movie(const std::string& strMovie) {

		size_t posS = 0;

		size_t posE = strMovie.find(',');

		// trim from posS to the length of token (poseE - posS)

		this->trim(m_title = strMovie.substr(posS, posE));



		// posS is the pos right after the found comma

		// posE - find the next comma starting from posS

		posS = posE + 1;

		posE = strMovie.find(',', posS);

		this->m_year = std::stoi(strMovie.substr(posS, posE - posS));



		posS = posE + 1;

		this->trim(m_description = strMovie.substr(posS));

	}



	// friend std::ostream& operator<<(std::ostream& os, const Movie& m)

	// FORMAT: "TITLE | YEAR | DESCRIPTION"

	//

	std::ostream& operator<<(std::ostream& os, const Movie& m) {

		os << std::setw(40) << m.m_title << " | " << std::setw(4) << m.m_year << " | " << m.m_description << std::endl;

		return os;

	}



}

