#include "ConfirmationSender.h"

namespace sdds {
	/*default constructor*/
	ConfirmationSender::ConfirmationSender() {
	}
	/*Copy constructor*/
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& confirm) {
		*this = confirm;
	}
	/*Move constructor*/
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& confirm) {
		*this = std::move(confirm);
	}
	/*Copy assignment Constructor */
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& confirm) {
		//self assignment
		if (this != &confirm) {
			for (size_t i = 0; i < this->count; i++) {
				delete this->reservation[i];
			}
			delete[] this->reservation;
			this->reservation = nullptr;
			this->count = 0;
			this->reservation = new (std::nothrow) Reservation * [confirm.count];
			for (size_t i = 0; i < confirm.count; i++) {
				this->reservation[i] = new (std::nothrow) Reservation(*confirm.reservation[i]);
				this->count++;
			}
		}
		return *this;
	}
	/*Move Constructor*/
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& confirm) {
		if (this != &confirm) {
			for (size_t i = 0; i < this->count; i++) {
				delete this->reservation[i];
			}
			delete[] this->reservation;
			this->reservation = confirm.reservation;
			this->count = confirm.count;
			confirm.reservation = nullptr;
			confirm.count = 0;
		}
		return *this;
	}
	/*+= operator*/ 
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool flag = true;
		for (size_t i = 0; i < this->count; i++) {
			if (this->reservation[i]->getID().compare(res.getID()) == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ConfirmationSender tem = std::move(*this);
			this->reservation = new (std::nothrow) Reservation * [tem.count + 1];
			for (size_t i = 0; i < tem.count; i++) {
				this->reservation[i] = new (std::nothrow) Reservation(*tem.reservation[i]);
				this->count++;
			}
			this->reservation[count++] = new (std::nothrow) Reservation(res);
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (size_t i = 0; i < this->count; i++) {
			if (this->reservation[i]->getID().compare(res.getID()) == 0) {
				ConfirmationSender tem = std::move(*this);
				this->reservation = new (std::nothrow) Reservation * [tem.count - 1];
				for (size_t j = 0; j < tem.count; j++) {
					if (j != i) {
						this->reservation[this->count++] = new (std::nothrow) Reservation(*tem.reservation[j]);
					}
				}
				break;
			}
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender() {
		for (size_t i = 0; i < this->count; i++) {
			delete reservation[i];
		}
		delete[] this->reservation;
	}
	void ConfirmationSender::display(std::ostream& os)const {
		for (size_t i = 0; i < this->count; i++) {
			os << *this->reservation[i];
		}
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (cs.count == 0) {
			os << "The object is empty" << std::endl;
		}
		else {
			cs.display(os);
		}
		os << "--------------------------" << std::endl;
		return os;
	}



}