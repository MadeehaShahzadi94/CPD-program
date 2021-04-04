/// Workshop 2 - Copy and Move Semantics
// TimedEvents.cpp (inLab)
// Name: Sammar Abbas
// Seneca Student ID: 157-597-170
// Seneca email: sabbas21@myseneca.ca
// Date of completion: Sep 20, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <chrono>
#include <iomanip>
#include "TimedEvents.h"
#include <string>

using namespace std;

namespace sdds {

	// default constructor
	TimedEvents::TimedEvents() {}

	// a modifier that starts the timer for an event
	void TimedEvents::startClock(){
		startTime = std::chrono::steady_clock::now();
	}

	// a modifier that stops the timer for an event
	void TimedEvents::stopClock(){
		stopTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* src){

		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime);
		
		if (numStoredRcd < max_Object) {
			this->record[numStoredRcd].m_eventName = src;
			this->record[numStoredRcd].m_unitOfTime = "nanoseconds";
			this->record[numStoredRcd].m_durationEvent = ms;
			numStoredRcd++;
		}
	}

	std::ostream& operator<< (std::ostream& os, const TimedEvents& record){

		for (int i = 0; i < 26; i++)
			os << "-";

		os << "\nExecution Times:\n";

		for (int i = 0; i < 26; i++)
			os << "-";

		os << endl;

			for (int i = 0; i < record.numStoredRcd; i++) {
				os << setw(20) << std::left
					<< record.record[i].m_eventName <<' ' << setw(12) <<right
					<< record.record[i].m_durationEvent.count() << ' '
					<< record.record[i].m_unitOfTime << endl;

			}

			for (int i = 0; i < 26; i++)
				os << "-";
			
			os << endl;
			return os;
	}


	TimedEvents::~TimedEvents(){}

}

