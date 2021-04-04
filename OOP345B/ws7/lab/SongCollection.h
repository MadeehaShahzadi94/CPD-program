#pragma once
// Name: Madeeha Shahzadi
// Seneca Student ID: 130638182
// Seneca email: mshahzadi1@myseneca.ca
// Date of completion:  March 18th 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H




#include <string>
#include <vector>
#include <iomanip>

namespace sdds {

	struct Song {

		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		std::string m_releaseYear;
		std::string m_length;
	};


	class SongCollection {

	private:
		std::vector <Song> m_song;


	public:
		SongCollection(const char* is);
		void display(std::ostream& out) const;

	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}



#endif