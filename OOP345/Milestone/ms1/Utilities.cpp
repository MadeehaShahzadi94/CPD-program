
#include "Utilities.h"

namespace std {
	char Utilities::m_delimiter = '\0';
	size_t Utilities::m_widthField = { 1 };

	//default constructor
	Utilities::Utilities()
	{
	}
	void Utilities::setFieldWidth(size_t incomWidth)
	{
		m_widthField = incomWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return size_t(m_widthField);
	}
	const std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more)
	{
		// find the next delimiter from 1 character after the previous one 
		size_t next_delimiter_pos = str.find(m_delimiter, next_pos + 1);	
		size_t word_length = (next_delimiter_pos - next_pos) - 1;			// get the length of the next word 
		std::string token = str.substr(next_pos + 1, word_length);			// extract the string that starts from next_pos with the length of the next word 
		// sets the next_pos to contain the position of the upcoming delimiter 
		next_pos = next_delimiter_pos;

		more = true;
		return token;

	}

		
	void Utilities::setDelimiter(const char incomD)
	{
		m_delimiter = incomD;
	}
	const char Utilities::getDelimiter() const
	{
		return this->m_delimiter;
	}

}
