// File Name:       VideoGame_Library.cpp
// Author Name(s):  Bryson Bargas and 
// Date:            09/24/2024
// Purpose:  

#include "VideoGame_Library.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

VideoGameLibrary::VideoGameLibrary(int maxGames){
    this->maxGames = maxGames;
    videoGamesArray = new videoGames[maxGames];
    numGames = 0;
};

void VideoGameLibrary::resizeVideoGameArray(){
    videoGames* placeHolder = new videoGames[maxGames * 2];

    for (int count = 0; count < numGames; count++) {
        placeHolder[count] = videoGamesArray[count];
    }

    delete[] videoGamesArray;
    videoGamesArray = placeHolder;
    maxGames *= 2;
};

void VideoGameLibrary::loadVideoGamesFromFile(string& filename){
    ifstream inputFile(filename);
    if(!inputFile){
        cout << "Error: Unable to open the file!";
    }

    int exit = 0;
    string title, platform, genre, ageRating, line;
    int year, userRating;
    int arrayCounter = 0;
    while(exit == 0){
        try{
            getline(inputFile, title);
            getline(inputFile, platform);
            getline(inputFile, line);
            year = stoi(line);
            getline(inputFile, genre);
            getline(inputFile, ageRating);
            getline(inputFile, line);
            userRating = stoi(line);
            videoGames(); // add arguments for constructor once made
        }catch(const invalid_argument &e){
            exit = 1;
        };

        if(exit == 0){
            cout << "\n" << title << " was added to the video game library!\n";
            numGames = numGames + 1;

        }

    };
    
};

void VideoGameLibrary::removeVideoGameFromArray(){
};

void VideoGameLibrary::saveToFile(string& filename){
};

VideoGameLibrary::~VideoGameLibrary(){
    delete[] videoGamesArray;
    cout << "\nvideoGamesArray: released memory\n";
};