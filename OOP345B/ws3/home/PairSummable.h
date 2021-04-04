// Name:Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@myseneca.ca
// Date of completion: Febuary 01,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include<iostream>
#include "Pair.h"
namespace sdds {
	template <typename K, typename V>
	class PairSummable : public Pair<K, V>
	{
		static V initial;
		static size_t fieldWidth;
	public:
		PairSummable() { }
		PairSummable(const K& key, const V& value) : Pair<K, V>(key, value)
		{
			if (fieldWidth < key.size())
				fieldWidth = key.size();
		}
		static const V& getInitialValue()
		{
			return initial;
		}

		V sum(const K& key, const V& val) const
		{
			return key == Pair<K, V>::key() ? val + Pair<K, V>::value() : val;
		}
		void display(std::ostream& os) const
		{
			os << std::left << std::setw(fieldWidth);
			Pair<K, V>::display(os);
			os << std::right;
		}
	};

	

	// initialize class variable
	//
	template <typename K, typename V>
	size_t PairSummable<K, V>::fieldWidth = 0;

	template <>
	std::string PairSummable<std::string, std::string>::initial = std::string("");

	template <>
	int PairSummable<std::string, int>::initial = 0;

	template <>
	std::string PairSummable<std::string, std::string>::sum(const std::string& k, const std::string& v) const
	{
		if (key() == k)
			return v == "" ? value() : v + std::string(", ") + value();
		else
			return v;
	}

}


#endif // !
