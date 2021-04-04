
#include "Item.h"


namespace std {
	Item::Item()
	{
	}
	Item::Item(std::string & incomingStr)
	{
		size_t next_pos = incomingStr.find(m_utility.getDelimiter());
		auto more = true;
		m_name = incomingStr.substr(0, next_pos);
		// extract token and convert from string to ulong 
		m_serialNumber = std::stoul(m_utility.extractToken(incomingStr, next_pos, more)); 
		
		m_quantity = std::stoi(m_utility.extractToken(incomingStr, next_pos, more));
		m_description = m_utility.extractToken(incomingStr, next_pos, more);


		// update the utility fieldWidth with the la length 
		if (m_utility.getFieldWidth() < m_name.length())
			m_utility.setFieldWidth(m_name.length());

	}
	Item::Item(Item && incomingObj)
	{
		if (this != &incomingObj)
		{
			m_name = incomingObj.m_name;
			m_description = incomingObj.m_description;
			m_serialNumber = incomingObj.m_serialNumber;
			m_quantity = incomingObj.m_quantity;


			incomingObj.m_name = { "" };
			incomingObj.m_description = { "" };
			incomingObj.m_serialNumber = { 0 };
			incomingObj.m_quantity = { 0 };
		}

	}
	const std::string & Item::getName() const
	{
		return m_name;
	}
	const unsigned int Item::getSerialNumber()
	{
		return m_serialNumber;
	}
	const unsigned int Item::getQuantity()
	{
		return m_quantity;
	}
	void Item::updateQuantity()
	{
		m_quantity--;
		//m_serialNumber++;

	}
	void Item::display(std::ostream & os, bool full) const
	{
		size_t fw = m_utility.getFieldWidth();
		


		if (full)
			os << std::left << std::setw(fw) << m_name
			<< " [" << std::setw(6) << std::right << setfill('0') << m_serialNumber << setfill(' ')
		<<"] Quantity: " << std::left << std::setw(fw) << m_quantity << std::right << " Description: " << m_description << std::endl;
		else
			os << std::left << std::setw(fw) << m_name << " [" << std::setw(6) << std::right<< setfill('0') << m_serialNumber << "]" << setfill(' ') << std::endl;

	}


}