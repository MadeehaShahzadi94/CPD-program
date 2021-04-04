// Name: Madeeha Shahzadi
// Seneca Student ID: 130638182
// Seneca email:mshahzadi1@gmail.com
// Date of completion:January 17,2020
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__
#include <string>
#include <cstring>
extern unsigned int g_sysClock; 
namespace sdds {


	class Event {

		char* m_description; 
		size_t m_time;

	public:
		Event();
		Event(const Event&);
		Event& operator=(const Event& );
		void display();
		void setDescription(const char* buffer);
		~Event();
	};



}
#endif

