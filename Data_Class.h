#include <iostream>
#include <Data_Class.cpp>
#include <fstream>

using namespace std;

class VideoGame{

public:

VideoGame(Text*, Text*, Text*, int, int);

~VideoGame();

Text* VideoGame::getVideoGameTitle() const;

void VideoGame::printVideoGameDeets();

void VideoGame::printVidGameDeetsFile(ofstream);



private:

Text *namePtr;
Text *devPtr;
Text *pubPtr;
int yr;
int rat;

}