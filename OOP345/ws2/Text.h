

#ifndef _SDDS_TEXT_H__
#define  _SDDS_TEXT_H__
#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <cstring>
#include <string>


namespace sdds {

	class Text {
		//dynamically allocated array
		std::string* S = nullptr;
		int stringStored; //track of number of strings currently stored

	public:
		Text(); // no-argument default constructor
		Text(const std::string&);
		
		Text(const Text&); // copy constructor
		Text& operator= (const Text&); // copy assignemnt operator
		~Text(); // destructor

		size_t size() const; // returns number of records stored


		Text(Text&&); // move constructor
		Text& operator= (Text&&); // move assignment operator
	};
}

#endif