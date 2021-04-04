#pragma once
// Name:Madeeha Shahzadi
// Seneca Student ID: 130638182
// Seneca email:mshahzadi1@myseneca.ca
// Date of completion: January 28, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>

using namespace std;

namespace sdds {
	//design the template
	//K: the type of the key
	//V: the type of the value
	template< typename K, typename V>
	class Pair {
		
		K t_key;
		V t_value;

	public:
		// default construc
		Pair() {}
		// 
		Pair(const K& key, const V& value) {
			t_key = key;
			t_value = value;
		}
		const K& key() const {
			//returns the key component of the pair
			return t_key;
		}
		const V& value() const {
			// returns the value component of the pair
			return t_value;
		}
		void display(std::ostream& os) const {
			os << t_key << " : " << t_value << std::endl;
		}
	};
	// a non - friend helper function that inserts into the
   // os object the LVPair object referenced in the 2nd function parameter
	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair< K, V>& pair) {

		pair.display(os);

		return os;
	}
}
#endif // !
