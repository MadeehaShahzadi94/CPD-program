/// Workshop 2 - Copy and Move Semantics
// TimedEvents.h (inLab)
// Name: Sammar Abbas
// Seneca Student ID: 157-597-170
// Seneca email: sabbas21@myseneca.ca
// Date of completion: Sep 20, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef _SDDS_TimedEvents_H__
#define  _SDDS_TimedEvents_H__
#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <chrono>
#include <string>


namespace sdds {

	const int max_Object = 7;
	
	class TimedEvents {
		
		int numStoredRcd = 0; // The number records currently stored

		std::chrono::steady_clock::time_point startTime; // The start time for the current event
		std::chrono::steady_clock::time_point stopTime; // The end time for the current event

		struct {
			std::string m_eventName; // string with the event name
			std::string m_unitOfTime; // string with the predefined units of time
			std::chrono::steady_clock::duration m_durationEvent; // The duration of the recorded event
		} record[max_Object]; // record can not exceed to 7

	public:
		TimedEvents(); // default constructor
		void startClock(); // a modifier that starts the timer for an event
		void stopClock(); // a modifier that stops the timer for an event
		void recordEvent(const char*);
		~TimedEvents(); // destructor

		friend std::ostream& operator<< (std::ostream& os, const TimedEvents&);


	};

}

#endif