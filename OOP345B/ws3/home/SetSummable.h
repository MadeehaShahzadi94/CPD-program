// Name:Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@myseneca.ca
// Date of completion:Febuary 01,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
//#include<iostream>
#include "Set.h"
//#include "PairSummable.h"


namespace sdds {
	template <typename T, size_t N, typename K, typename V>
	class SetSummable : public Set<T, N>
	{
	public:
		V accumulate(const K& key) const

		{
			V sum = T::getInitialValue();
			for (size_t i = 0; i < this->size(); i++)
			{
				sum = (*this)[i].sum(key, sum);  			}
			return sum;
		}
	};

	

}
#endif