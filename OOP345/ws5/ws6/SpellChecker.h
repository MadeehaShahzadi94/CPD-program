#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_SPELLCHECKER_H

#define SDDS_SPELLCHECKER_H



#include <iostream>

#include <string>

#include <fstream>



namespace sdds

{

	class SpellChecker

	{

	private:

		std::string m_badWords[5];

		std::string m_goodWords[5];

		int cnt = 0;

	public:

		SpellChecker();

		SpellChecker(const char* filename);

		void operator()(std::string& text) const;

	};

}



#endif // !SDDS_SPELLCHECKER_H