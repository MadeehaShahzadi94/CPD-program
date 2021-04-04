// Name: Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@myseneca.on.ca
// Date of completion:16 Feb 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>
namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[5];
		std::string m_goodWords[5];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}
#endif