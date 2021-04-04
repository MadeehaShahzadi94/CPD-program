

#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include "Text.h"
#include <fstream>

using namespace std;

namespace sdds {

	Text::Text() {
		S = nullptr;
		stringStored = 0;
	}

	Text::Text(const string& fName)
	{
		std::ifstream f(fName.c_str());
		stringStored = 0;
		S = nullptr;
		if (!f)
			return;
		do
		{
			char c = f.get();
			if (c == ' ')
				stringStored++;
		} while (!f.eof());

		f.seekg(std::ios::beg);
		S = new std::string[stringStored];

		for (int i = 0; i < stringStored; i++)
			std::getline(f, S[i], ' ');

	}


	// copy constructor

	Text::Text(const Text& rhs) {
		delete[] S;
		*this = rhs;
	}

	// copy assignment operator
	Text& Text::operator= (const Text& other) {
		if (this != &other) {
			delete[] S;
			stringStored = other.stringStored;
			S = new string[stringStored];

			for (int i = 0; i < stringStored; i++) {
				S[i] = other.S[i];
			}
		}
		
		return *this;
	}

	// move constructor
	Text::Text(Text&& other) {
		*this = move(other);
	}

	// move assignment operator
	Text& Text::operator= (Text&& rhs) {
		if (this != &rhs) {
			delete[] S;
			
			S = rhs.S;
			stringStored = rhs.stringStored;

			rhs.S = nullptr;
			rhs.stringStored = 0;
		}

		return *this;
	}



	Text::~Text() {
		delete[] S;
	}

	size_t Text::size() const {
		return stringStored;
	}

}

