// File Name:       VideoGame_Library.cpp
// Author Name(s):  Bryson Bargas and 
// Date:            09/24/2024
// Purpose:  

#include "VideoGame_Library.h"
#include <fstream>
#include <iostream>
using namespace std;

VideoGameLibrary::VideoGameLibrary(int maxGames){
    videoGamesArray = new videoGames[maxGames];
};

void VideoGameLibrary::resizeVideoGameArray(){
    placeHolder = new videoGames[maxGames*2];
    int count = 0;
    while(count <= maxGames){
        videoGamesArray[count] = placeHolder[count];
        count++;
    } delete[] videoGamesArray;

    count = 0;
    videoGamesArray = new videoGames[maxGames*2];
    while(count <= maxGames){
        placeHolder[count] = videoGamesArray[count];
        count++;
    } delete[] placeHolder;

    setMaxGames(maxGames*2);
};

void VideoGameLibrary::setMaxGames(int numGames){
    maxGames = numGames;
};

void VideoGameLibrary::loadVideoGamesFromFile(string& filename){
    
};

void VideoGameLibrary::removeVideoGameFromArray(){
};

void VideoGameLibrary::saveToFile(string& filename){
};

VideoGameLibrary::~VideoGameLibrary(){
    delete[] videoGamesArray;
    cout << "\nvideoGamesArray: released memory\n";
};