
#include "SpellChecker.h"



namespace sdds {



	// SpellChecker();

	//

	SpellChecker::SpellChecker() {

		m_badWords[0] = '\0';

		m_goodWords[0] = '\0';

	}



	// SpellChecker(const char* filename);

	//

	SpellChecker::SpellChecker(const char* filename) {

		std::string temp;

		std::ifstream f(filename);

		if (!f)

		{

			throw "Bad file name!";

		}

		else {

			do

			{

				std::getline(f, temp);

				if (f)

				{

					size_t i = 0u;

					size_t posS = 0u;

					size_t posE = temp.find(' ');

					m_badWords[cnt] = temp.substr(posS, posE - posS);

					temp.erase(posS, posE - posS);

					for (i = 0; i < temp.length() && temp[i] == ' '; i++);

					posS = i;

					m_goodWords[cnt] = temp.substr(posS);

					cnt++;

				}

			} while (f);

		}

		f.close();

	}



	//void operator()(std::string& text) const;

	//

	void SpellChecker::operator()(std::string& text) const {

		size_t position = 0u;



		// loop through array of bad words and search the recieved text for them

		for (int i = 0; i < cnt; i++) {

			position = text.find(m_badWords[i]);

			if (position != text.npos) {



				// Search until the end of the string

				while (position != text.npos) {

					text.replace(position, m_badWords[i].length(), m_goodWords[i]);

					position = text.find(m_badWords[i]);

				}

			}

		}

	}



}