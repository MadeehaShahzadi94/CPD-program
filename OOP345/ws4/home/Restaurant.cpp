#include"Restaurant.h"

namespace sdds {
	/*Default Constructor*/
	Restaurant::Restaurant() {
	}
	/*Two argument Constructor*/
	Restaurant::Restaurant(Reservation* reservation[], size_t cnt) {
		/*
		1. constructor receive a parameter
		2. when refresh the array of pointers, it reread the material form the last term
		3. this constructor should store copies of all reservations*/
		if (reservation != nullptr)// it is must in safe
		{
			//allocation of Memory
			this->reservation = new(std::nothrow) Reservation[cnt];
			if(this->reservation!= nullptr)
				for (size_t index = 0; index < cnt; index++)
				{
					//copy
					this->reservation[index] = *reservation[index];
					this->count++;// i am not confirm
				}
		}
	}
	/*copy constructor*/
	Restaurant::Restaurant(const Restaurant& res)
	{
		/*return current object*/
		*this = res;
	}
	/*Move constructor*/
	Restaurant::Restaurant(Restaurant&& res)
	{
		//copy constructor is moved to this constructor
		*this = std::move(res);
	}

	std::size_t Restaurant::size() const
	{
		// return the size_t
		// why -> is working here not . or *pointer
		return this->count;
	}
	bool Restaurant::isEmpty()const {
		return this->reservation == nullptr ? true : false;

	}

	void Restaurant::display(std::ostream& os)const {
		for (size_t i = 0; i < this->count; i++) {
			os << this->reservation[i];
		}
	}
	Restaurant& Restaurant::operator=(const Restaurant& res)
	{
		// TODO: insert return statement here
		// check the memory(self Assignment)
		// we are checking current and reservation also
		if (this != &res && res.reservation != nullptr) {
			//delete the current memory
			delete[] reservation;
			reservation = nullptr;
			//allocation of new memory
			reservation = new(std::nothrow) Reservation[res.count];
			if (reservation != nullptr) {
				for (size_t index = 0; index < res.count; index++) {
					reservation[index] = res.reservation[index];
					count++;
				}
			}
		}
		return *this;
	}
	Restaurant& Restaurant::operator=(Restaurant&& rest) {
		if (this != &rest && rest.reservation != nullptr) {
			delete[] this->reservation;
			this->reservation = nullptr;
			this->count = 0;

			this->reservation = rest.reservation;
			this->count = rest.count;
			rest.reservation = nullptr;
			rest.count = 0;
		}
		return *this;
	}
	/* destructor*/
	Restaurant::~Restaurant()
	{
		delete[] reservation;
	}
	/* friend helper function*/
	std::ostream& operator<<(std::ostream& os, const Restaurant& rest) {
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;
		if (rest.count == 0) {
			os << "The object is empty" << std::endl;
		}
		else {
			rest.display(os);
		}
		os << "--------------------------" << std::endl;
		return os;
	}
	



}