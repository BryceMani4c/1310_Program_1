#ifndef VIDEO_GAME_LIBRARY_H
#define VIDEO_GAME_LIBRARY_H

#include "VideoGame.h"
using namespace std;

class VideoGameLibrary{
public:
    VideoGameLibrary(int capacity);
    void resizeVideoGameArray();
    void loadVideoGamesFromFile(string& filename);
    void removeVideoGameFromArray();
    void saveToFile(string& filename);
    void setMaxGames(int numGames);
    ~VideoGameLibrary();

private:
    videoGames* videoGamesArray;
    videoGames* placeHolder;
    int maxGames;
    int numGames;

};

#endif