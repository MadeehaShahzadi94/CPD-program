// Name: Madeeha Shahzadi
// Seneca Student ID: 130638182
// Seneca email:mshahzadi1@myseneca.ca
// Date of completion:March 22nd, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


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
         
            std::string tmpLength = "";
            tmpLength = line.substr(80, 5);
            tmpLength.erase(0, tmpLength.find_first_not_of(" "));
            tmpLength.erase(tmpLength.find_last_not_of(" ") + 1);
            tmp.m_length = stoi(tmpLength);

            tmp.m_price = stod(line.substr(85, 5));
            m_song.push_back(tmp);
        }

    }



    void SongCollection::display(std::ostream& out) const {
        size_t totalTime = 0;
        size_t hour = 0;
        size_t min = 0;
        size_t sec = 0;
        std::string t_min;
        std::string t_sec;
        for_each(m_song.begin(), m_song.end(), [&](const Song& str) {
            out << str << std::endl;
            totalTime += str.m_length;
            });
        out << "----------------------------------------------------------------------------------------" << std::endl;
        out << "|                                                        Total Listening Time: ";
        while (totalTime >= 3600) {
            hour++;
            totalTime -= 3600;
        }
        min = totalTime / 60;
        sec = totalTime % 60;
        if (sec < 10) {
            t_sec = "0" + std::to_string(sec);
        }
        else {
            t_sec = std::to_string(sec);
        }
        if (min < 10) {
            t_min = "0" + std::to_string(min);
        }
        else {
            t_min = std::to_string(min);
        }
        out << std::to_string(hour) << ":" << t_min << ":" << t_sec;
        out << " |" << std::endl;


    }


        
    void SongCollection::sort(std::string str) {
    
        std::sort(m_song.begin(), m_song.end(), [=](Song s1, Song s2) {

            bool ok = true;
            if (str == "title") {
                ok = s1.m_title < s2.m_title;
            }
            else if (str == "album") {
                ok = s1.m_album < s2.m_album;
            }
            else if(str == "length") {
                ok = s1.m_length < s2.m_length;
            }
        
            return ok;
        });
        
    
    
    }



    void SongCollection::cleanAlbum() {
    
        for_each(m_song.begin(), m_song.end(), [](Song& s) {
            if (s.m_album == "[None]") s.m_album.clear();
        });
    
    }



    bool SongCollection::inCollection(const char* str) const {
       
        bool res = false;
        for_each(m_song.begin(), m_song.end(), [&](const Song& s) {
            if (s.m_artist == str) {
                res = true;
            }

        });
        
        return res;
    }



    std::list<Song> SongCollection::getSongsForArtist(const char* str) const {
    
        std::list<Song> g_song;
        for_each(m_song.begin(), m_song.end(), [&](const Song& s) {
            if (s.m_artist == str) {
                g_song.push_back(s);
            }

        });

        return g_song;
    }



    std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        out << "| " << std::left << std::setw(20) << theSong.m_title
            << " | " << std::setw(15) << theSong.m_artist
            << " | " << std::setw(20) << theSong.m_album
            << " | " << std::right << std::setw(6) << theSong.m_releaseYear;
        out << " | " << theSong.m_length / 60 << ":";
        
        
        if (theSong.m_length % 60 < 10) {
            out << "0" << theSong.m_length % 60;
        }
        else {
            out << theSong.m_length % 60;
        }


        out << " | " << theSong.m_price << " |";



        return out;
    }







}