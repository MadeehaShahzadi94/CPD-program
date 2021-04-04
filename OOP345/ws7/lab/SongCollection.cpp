// Name: Iram Rahimi
// Seneca Student ID: 138503172
// Seneca email:irahimi@myseneca.ca
// Date of completion:03/12/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <fstream>
#include <algorithm> 
#include "SongCollection.h"



using namespace std;
namespace sdds {

    SongCollection::SongCollection(const char* is) {
        std::ifstream file(is);

        if (!file) {
            throw "Invalid file";
        }
        while (!file.eof()) {

            std::string line;
            getline(file, line, '\n');
            struct Song tmp;

            tmp.m_artist = line.substr(25, 25);
            tmp.m_artist.erase(0, tmp.m_artist.find_first_not_of(" "));
            tmp.m_artist.erase(tmp.m_artist.find_last_not_of(" ") + 1);


            tmp.m_title = line.substr(0, 25);
            tmp.m_title.erase(0, tmp.m_title.find_first_not_of(" "));
            tmp.m_title.erase(tmp.m_title.find_last_not_of(" ") + 1);


            tmp.m_album = line.substr(50, 25);
            tmp.m_album.erase(0, tmp.m_album.find_first_not_of(" "));
            tmp.m_album.erase(tmp.m_album.find_last_not_of(" ") + 1);

            tmp.m_releaseYear = line.substr(75, 5);
            tmp.m_releaseYear.erase(0, tmp.m_releaseYear.find_first_not_of(" "));
            tmp.m_releaseYear.erase(tmp.m_releaseYear.find_last_not_of(" ") + 1);

            tmp.m_length = line.substr(80, 5);
            tmp.m_length.erase(0, tmp.m_length.find_first_not_of(" "));
            tmp.m_length.erase(tmp.m_length.find_last_not_of(" ") + 1);

            size_t tmpLength = stod(tmp.m_length);
            size_t min = tmpLength / 60;
            size_t sec = tmpLength % 60;
            std::string t_sec = "";

            if (sec < 10) {
                t_sec = "0" + std::to_string(sec);
            }
            else {
                t_sec = std::to_string(sec);
            }
            tmp.m_length = std::to_string(min) + ":" + t_sec;

            tmp.m_price = stod(line.substr(85, 5));
            m_song.push_back(tmp);
        }

    }



    void SongCollection::display(std::ostream& out) const {
        std::for_each(m_song.begin(), m_song.end(), [&out](auto x) {
            out << x << std::endl;
            });
    }



    std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        out << "| " << std::left << std::setw(20) << theSong.m_title << " | "
            << std::setw(15) << theSong.m_artist << " | " << std::setw(20)
            << theSong.m_album << " | " << std::right << std::setw(6)
            << theSong.m_releaseYear << " | "
            << theSong.m_length << " | " << theSong.m_price << " |";
        return out;
    }







}