// Name: Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@mysenecac.on.ca
// Date of completion:Jan 22,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "RecordSet.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
namespace sdds
{
	RecordSet::RecordSet()
	{

	}
	RecordSet::RecordSet(const string& file_name) { // this for file

		std::ifstream file;

		file.open(file_name); // open file 


		std::string temp;

		// if file is opened
		if (file)
		{
			// until the end of the file 
			while (!file.eof()) {
				if (getline(file, temp, ' ')) {
					++stringStored;
				}
			}
			S = new std::string[stringStored]; // allocate memory

			file.close(); // close file to reset

			file.open(file_name);

			// Copy all into m_file_name 
			for (unsigned int i = 0; i < stringStored; ++i)
			{
				getline(file, S[i], ' ');
			}
		}

		else {
			std::cerr << "File has not opened!" << std::endl;
		}
	}


	RecordSet::RecordSet(const RecordSet& rhs)
	{
		*this = rhs;
	}

	RecordSet& RecordSet::operator=(const RecordSet& rhs)
	{
		// TODO: insert return statement here
		if (this != &rhs)
		{
			//delete memory allocation
			delete[] S;
			stringStored = rhs.stringStored;
			// allocation of new memory
			S = new string[stringStored];
			//checking the string
			for (size_t index = 0; index < stringStored; index++)
			{
				S[index] = rhs.S[index];
			}
		}
		return *this;
	}

	RecordSet::RecordSet(RecordSet&& rhs)
	{
		*this = move(rhs);
	}

	RecordSet& RecordSet::operator=(RecordSet&& rhs)
	{
		if (this != &rhs) {

			delete[] S;
			S = rhs.S;
			stringStored= rhs.stringStored;
			rhs.S = nullptr;
			rhs.stringStored = 0;
		}

		return*this;
	}

	
		
	size_t RecordSet::size()
	{
		return stringStored;
	}

	std::string RecordSet::getRecord(size_t size)
	{
		/* a query that returns the record at the index received as parameter. If the index is invalid, this function should return the empty string.*/


		if (size < stringStored && size >= 0)
		{
			return S[size];
		}
		return "";
		/*if (size < 0)
			return "";
		else if (size >= stringStored)
			return "";
		else
			return size;*/
	}

	RecordSet::~RecordSet()
	{
		delete[] S;
	}
}