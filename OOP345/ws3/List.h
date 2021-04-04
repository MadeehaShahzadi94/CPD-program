#ifndef List_H
#define List_H
#include<iostream>
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>

namespace sict {
	template<typename T , size_t N >
	class List {
		T list[N];
		size_t number_of_elements{0};

	public:

		size_t size() const { return number_of_elements; };

		const T& operator[](size_t i) const { return list[i]; };

		void operator+=(const T& src) {
			if (number_of_elements < N) {
				list[number_of_elements] = src;
				number_of_elements++;

			};

		};

	};

	
	
	

	template<typename T, typename L, typename V, size_t N>
	class LVList:public List{
		V accumulate(const L& label)const {
			V TOL = SummableLVPair<L, V>::getinitialValue();
				List<T,N>& temp = (List<T, N>&)*this;
				for ( size_t i = 0; i <temp.size(); i++)
				{
					if (label == temp[i].getlable()) {
						TOL = temp[i].sum(label, TOL);						
					}
				}
		
				return	TOL;
		}
	
	
	
	
	};
};

#endif // !List_H



