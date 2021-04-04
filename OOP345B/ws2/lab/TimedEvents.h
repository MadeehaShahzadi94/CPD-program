// Name: Madeeha Shahzadi
// Seneca Student ID:130638182
// Seneca email:mshahzadi1@mysenecac.on.ca
// Date of completion:Jan 22,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_TimedEvents_H__
#define  _SDDS_TimedEvents_H__
#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <chrono>
#include <string>


namespace sdds {

	const int max_Object = 7;

	class TimedEvents {

		size_t numStoredRcd = 0; // The number records currently stored

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