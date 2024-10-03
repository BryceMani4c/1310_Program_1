// File Name:       VideoGame_Library.cpp
// Author Name(s):  Bryson Bargas and Mal Flesher
// Date:            09/24/2024
// Purpose:  

#include "VideoGame_Library.h"
#include "Data_Class.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

VideoGameLibrary::VideoGameLibrary(int maxGames){
    this->maxGames = maxGames;
    this->numGames = 0;
    videoGamesArray = new VideoGame*[maxGames];
    for (int i = 0; i < maxGames; ++i) {
        videoGamesArray[i] = nullptr;
    }
};

void VideoGameLibrary::resizeVideoGameArray(){
    VideoGame** placeHolder = new VideoGame*[maxGames * 2];
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
    string title, dev, pub;
    int year, userRating;
    int arrayCounter = 0;
    while(exit == 0){
        try{

            getline(inputFile, title);
            Text titleText = Text(title.c_str(), title.length());
            videoGamesArray[arrayCounter]->setTitle(&titleText);

            getline(inputFile, dev);
            Text devText = Text(dev.c_str(), dev.length());
            videoGamesArray[arrayCounter]->setDeveloper(&devText);

            getline(inputFile, pub);
            Text pubText = Text(pub.c_str(), pub.length());
            videoGamesArray[arrayCounter]->setPublisher(&pubText);

            inputFile >> year;
            inputFile >> userRating;
            inputFile.ignore();

            videoGamesArray[arrayCounter]->setYearOfRelease(year);
            videoGamesArray[arrayCounter]->setRating(userRating);

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
if(numGames <= 1) {
    cout << "\nThere must always be at least one video game in the library." << endl;
    return;
}else{
    displayVideoGameTitles(); // double check this is correct once made
    int choice;
    cout << "\nEnter the number of the video game you wish to remove (1 to " << numGames << "); ";
    cin >> choice;

    for (int i = choice - 1; i < numGames - 1; i++) {
        videoGamesArray[i] = videoGamesArray[i + 1];
    }

    cout << "Game number " << choice << " has been removed";
};
};

void VideoGameLibrary::saveToFile(string& filename){
    ofstream outputFile(filename);
    if(!outputFile){
        cout << "Error: Unable to open the file!";
    }
    else{
        for(int i = 0; i < numGames; i++){
            videoGamesArray[i]->printVidGameDeetsFile(outputFile);
        }
    }

    outputFile.close();

    cout << "All video games have been printed to " << filename << "." << endl;
};

VideoGameLibrary::~VideoGameLibrary(){
    delete[] videoGamesArray;
    cout << "\nvideoGamesArray: released memory\n";
};

void VideoGameLibrary::addVideoGameToArray()
{
    //ask user for info
    string title, dev, pub;
    int yr, rat;
    cout << "Title:\t" << endl;
    getline(cin,title);
    Text titleText = Text(title.c_str(), title.length());
    videoGamesArray[numGames]->setTitle(&titleText);
    cout << "Developer:\t" << endl;
    getline(cin,dev);
    Text devText = Text(dev.c_str(), dev.length());
    videoGamesArray[numGames]->setDeveloper(&devText);
    cout << "Publisher:\t" << endl;
    getline(cin, pub);
    Text pubText = Text(pub.c_str(), pub.length());
    videoGamesArray[numGames]->setPublisher(&pubText);
    cout << "Rating:\t" << endl;
    cin >> rat;
    cin.ignore();
    videoGamesArray[numGames]->setRating(rat);
    cout << "Year:\t" << endl;
    cin >> yr;
    cin.ignore();
    videoGamesArray[numGames]->setRating(yr);

    //adding video game & checking size/resizing
    if (numGames < maxGames) {
        VideoGame* newGame= new VideoGame(videoGamesArray[numGames]->getVideoGameTitle(),videoGamesArray[numGames]->getDeveloper(), videoGamesArray[numGames]->getPublisher(), videoGamesArray[numGames]->getRating(), videoGamesArray[numGames]->getYearOfRelease());
        videoGamesArray[numGames] = newGame;
        cout << "Video game added successfully" << endl;
    }
    else {
        cout << "Video game not added successfully" << endl;
        resizeVideoGameArray();
        addVideoGameToArray();
    }

    numGames++;
}

void VideoGameLibrary::displayVideoGames()
{
    if(numGames > 0) {
        for (int i=0; i < numGames; i++) {
            videoGamesArray[numGames]->printVideoGameDeets();
        }
    }
    else {
        cout << "Library id empty. No video games to display." << endl;
    }
}

void VideoGameLibrary::displayVideoGameTitles()
{
    //variables
    string Norman;

    if(numGames > 0){
        for (int i=0; i < numGames; i++) {
            videoGamesArray[i]->getVideoGameTitle()->displayText();
        }
    }
    else {
        cout << "Library id empty. No video games to display." << endl;
    }
}