#pragma once
// Name:Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@myseneca.ca
// Date of completion: January 28,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <iostream>

using namespace std;
namespace sdds {
	//Design a template
	//T: the type of any element in the array
	//N: the maximum mum
	template<typename T,size_t N>
	class Set {
		//the capacity of the array(N)
		T array_list[N];
		//the number of elements added to the set. Initially the set is empty.
		size_t num_elements = 0;
	public:
		//returns the number of elements 
		size_t size() const {

			return num_elements;
		}
		//in the overloaded operator we receives an index of size_t then
	   //we returns a array_list to the object
		const T& operator[](size_t idx) const {
			return array_list[idx];
		}
		//an overloaded operator receives a reference
		//to an unmodifiable object t of type T.
		void operator+=(const T& item) {

			if (num_elements < N)
			{

				array_list[num_elements] = item;
				num_elements++;
			}
		}

	};

}




#endif