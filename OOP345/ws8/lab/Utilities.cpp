// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (auto index = 0u; index < desc.size(); index++) {
			for (auto j = 0u; j < price.size(); j++) {
				if (desc[index].code == price[j].code) {
					//unique_ptr<Product> p(new Product(desc[index].desc, price[j].price);
					Product* p = new Product(desc[index].desc, price[j].price);
					p->validate();
					//priceList += std::move(p);
					priceList += p;
					delete p;
					
					
				}
			}
		}


		return priceList;
	}
}