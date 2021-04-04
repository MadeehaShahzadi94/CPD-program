// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// Name: Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@mysenecac.on.ca
// Date of completion:Feb 12,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	{

		// TODO: load the collection of books from the file "argv[1]".
		std::ifstream file(argv[1]);
		if (!file) {
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}
		//file.clear();
		//file.seekg(std::ios::beg);
		std::string strlibrary;
		size_t i = 0;
		do {
		//       - read one line at a time, and pass it to the Book constructor
			std::getline(file, strlibrary);
			if (file) {
		//       - store each book read into the array "library"
				if (strlibrary[0] != '#')
				{
		//       - lines that start with "#" are considered comments and should be ignored
					library[i] = strlibrary;
					++i;
				}
			}
		} while (file);

		file.close();
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto fixedPrice = [usdToCadRate, gbpToCadRate](Book& incomcoming)mutable
	{


		if (incomcoming.country() == "US")
			incomcoming.price() *= usdToCadRate;

		if (incomcoming.year() >= 1990 && incomcoming.country() == "UK")
			incomcoming.price() *= gbpToCadRate;


		return incomcoming;
	};


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (auto& book : library)     //    using the lambda defined above.
		fixedPrice(book);

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}
