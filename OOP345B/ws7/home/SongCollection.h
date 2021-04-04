// Name: Madeeha Shahzadi
// Seneca Student ID: 130638182
// Seneca email:mshahzadi1@myseneca.ca
// Date of completion:March 22nd, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <vector>
#include <iomanip>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <cstring>
#include <string>
namespace sdds {

	struct Song {

		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		std::string m_releaseYear;
		size_t m_length;
	};


	class SongCollection {

	private:
		std::vector <Song> m_song;


	public:
		SongCollection(const char* is);
		void display(std::ostream& out) const;
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(const char*) const;
		std::list<Song> getSongsForArtist(const char*) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}



#endif