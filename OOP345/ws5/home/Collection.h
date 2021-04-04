#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_COLLECTION_H

#define SDDS_COLLECTION_H



#include <iostream>

#include <stdexcept>



namespace sdds 

{

	template<typename T>

	class Collection

	{

	private:

		std::string m_name = "";

		T* m_collection = nullptr;

		size_t cnt = 0u;

		// will hold the address of a function set below

		void (*m_ptrToFunc)(const Collection<T>&, const T&) = nullptr;

	public:

		Collection() {};

		Collection(std::string name)

			: m_name{ name }

		{}

		Collection(const Collection&) = delete;

		Collection& operator=(const Collection&) = delete;

		~Collection() 

		{

			delete[]m_collection;

			m_collection = nullptr;

		}

		const std::string& name() const { return m_name; };



		// return size of collection

		//

		size_t size() const { return cnt; };



		// SetObserver, sets callback function to pointer data member

		//

		void setObserver(void (*observer)(const Collection<T>&, const T&)) 

		{

			//m_ptrToFunc = void (*observer)(const Collection<T>&, const T&);

			m_ptrToFunc = observer;

		}



		// Collection += operator

		//

		Collection<T>& operator+=(const T& item)

		{

			bool found = false;

			for (size_t i = 0; i < cnt && found == false; i++) {

				if (m_collection != nullptr && m_collection[i].title() == item.title()) {

					found = true;

					return *this;

				}

			}

			if (found == false) {

				T* tempCollection = new T[cnt + 1];

				for (auto i = 0; i < cnt; ++i) {

					tempCollection[i] = m_collection[i];

				}

				tempCollection[cnt] = item;



				delete[]m_collection;

				m_collection = tempCollection;

				cnt++;



				if (m_ptrToFunc != nullptr) {

					m_ptrToFunc(*this, m_collection[cnt - 1]);

				}

			}

			return *this;

		}

		T& operator[](size_t idx) const {

			if (idx >= cnt) {

				std::string msg = "Bad index [";

				msg += std::to_string(idx);

				msg += "]. Collection has [";

				msg += std::to_string(cnt);

				msg += "] items.";

				throw std::out_of_range(msg);

			}

			return m_collection[idx];

		}

		T* operator[](std::string title) const {

			size_t i = 0u;

			bool found = false;

			for (i = 0u; i < cnt && found == false; i++) {

				if (m_collection[i].title() == title) {

					found = true;

				}

			}

			return found == true ? &(m_collection[i - 1]) : nullptr;

		}

	};

	template<typename T>

	std::ostream& operator<<(std::ostream& os, const Collection<T>& c) {

		for (size_t i = 0; i < c.size(); i++) {

			os << c[i];

		}

		return os;

	};

}



#endif // !SDDS_COLLECTION_H