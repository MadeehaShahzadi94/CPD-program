
#ifndef ITEM_H
#define ITEM_H
#include<string>
#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"
namespace std {
	class Item {

		std::string m_name;
		std::string m_description;
		long m_serialNumber;
		size_t m_quantity;
		const size_t m_widthField = 1;
		Utilities m_utility;

	public:
		Item();
		Item(std::string& incomingStr);
		Item(const Item& incomingObj) = delete;
		Item& operator=(const Item& incomingObj) = delete;
		Item(Item&& incomingObj);
		Item& operator=(Item&& incomingObj) = delete;

		const std::string& getName() const;
		const unsigned int getSerialNumber();
		const unsigned int getQuantity();
		void updateQuantity();
		void display(std::ostream& os, bool full) const;

	};
}
#endif // !ITEM_H
