#ifndef VIDEOGAME_LIBRARY_H
#define VIDEOGAME_LIBRARY_H

#include "Data_Class.h"
using namespace std;

class VideoGameLibrary{
public:
    VideoGameLibrary(int capacity);
    void resizeVideoGameArray();
    void loadVideoGamesFromFile(string& filename);
    void removeVideoGameFromArray();
    void saveToFile(string& filename);
    ~VideoGameLibrary();

private:
    VideoGame** videoGamesArray;
    int maxGames;
    int numGames;

};

#endif