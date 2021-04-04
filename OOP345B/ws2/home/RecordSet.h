#pragma once
// Name: Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@mysenecac.on.ca
// Date of completion:Jan 22,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_RECORDSET_H__
#define  _SDDS_RECORDSET_H__
#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <cstring>
#include <string>

namespace sdds {
	class RecordSet {
		//dynamic allocation of array
		std::string* S = nullptr;
		size_t stringStored = 0; //track of number of strings currently stored
	public:
		// no-argument default constructor
		RecordSet();
		//One argument constructor
		RecordSet(const std::string&);
		//a copy constructor
		RecordSet(const RecordSet&);
			//a copy assignment operator
		RecordSet& operator =(const RecordSet&);
		//Move Constructor
		RecordSet(RecordSet&&);
		//Move Assignment Move Constructor
		RecordSet& operator =( RecordSet&&);
		//a query that returns the number of records stored in the current object.
		size_t size();
		//returns the record at the index received as parameter
		std::string getRecord(size_t);
		//destructor
		~RecordSet();

	};
}








#endif