// Name: Madeeha Shahzadi
// Seneca Student ID: 130638182
// Seneca email:mshahzadi1@gmail.com
// Date of completion:January 17,2020
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
// In display copy constructor, i take help to my friend.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"
#include <iomanip>
using namespace std;
//global variable named g_sysClock store positive integer
	// integer between 0 to 86400 and must be midnight time
	//extern used external linkage

unsigned int g_sysClock = 86400;
namespace sdds {
	Event::Event() {
		m_description = nullptr;
		m_time = 0;
	}
	Event::Event(const Event& event){
		setDescription(event.m_description);
		m_time = event.m_time;
	}
	
	Event& Event::operator=(const Event& event)
	{
		setDescription(event.m_description);
		m_time = event.m_time;
		return *this;
	}
	// i take help to the friend
	void Event::display()
	{
		static int count;
		count++;
		unsigned int hour = 0;
		hour = m_time / 3600;
		unsigned int mint = 0;
		mint = (m_time % 3600) / 60;
		unsigned int sec = 0;
		sec = (m_time % 3600) % 60;
		if (m_description == nullptr || m_description[0] == '\0') {

			cout << setw(3) << setfill(' ') << count << ". " << "[ No Event ]" << endl;

			g_sysClock = 0;
		}
		else {
			cout.width(3);
			cout.fill(' ');
			cout << count;
			cout << ". " << setw(2) << setfill('0') << hour << ":" << setw(2) << mint << ":" << setw(2) << sec << " -> " << m_description << endl;
		}
	}
	void Event::setDescription(const char* buffer) {	
		if (buffer != nullptr && buffer[0] != '\0') {	
			delete[] m_description;	
			m_description = new char[strlen(buffer) + 1];
			strncpy(m_description, buffer, strlen(buffer)+1);
			m_time = g_sysClock;
		}
		else {
			m_description = nullptr;
			m_time = 0;
		}
	}
	Event::~Event() {
		delete[]m_description;
	}

}

