#ifndef _SICT_STRING_H
#define _SICT_STRING_H

namespace sict
{
	class string
	{
		char m_string[4];		// C-style null terminated string INCL null terminator
	public:
		string(const char*);
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, string&);

}

#endif // !_SICT_STRING_H
