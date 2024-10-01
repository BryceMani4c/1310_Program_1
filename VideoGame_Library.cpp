// File Name:       VideoGame_Library.cpp
// Author Name(s):  Bryson Bargas and Mal Flesher
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

    for (int i = 0; i < numGames; i++) {
        videoGamesArray[i].printVideoGameDetailsToFile(outputFile);
    };

    outputFile.close();

    cout << "All video games have been printed to " << filename << "." << endl;
};

VideoGameLibrary::~VideoGameLibrary(){
    delete[] videoGamesArray;
    cout << "\nvideoGamesArray: released memory\n";
};




//mal
//have to go through can replace variables

void addVideoGameToArray()
{
    //ask user for info
    cout << "Title:\t" << endl;
    getline(cin, title);
    cout << "Developer:\t" << endl;
    getline(cin, developer);
    cout << "Publisher:\t" << endl;
    getline(cin, publisher);
    cout << "Rating:\t" << endl;
    cin >> rating;
    cin.ignore();
    cout << "Year of Release:\t" << endl;
    cin >> release;
    cin.ignore();

    //adding video game & checking size/resizing
    if (numGames < maxGames) {
        videoGames newGame;
        cin >> newGame;
        videoGames[numGames] = newGame;
        cout << "Video game added successfully" << endl;
    }
    else {
        cout << "Video game not added successfully" << endl;
        resizeVideoGameArray();
        addVideoGametoArray();
    }

    numGames++;
}

void displayVideoGames()
{
    if(numGames > 0) {
        for (int i=0; i < numGames; i++) {
            cout << gamesArray[printVideoGameDetails()] << endl;
        }
    }
    else {
        cout << "Library id empty. No video games to display." << endl;
    }
}

void displayVideoGameTitles()
{
    //variables
    string Norman;

    if(numGames > 0){
        for (int i=0; i < numGames; i++) {
            Norman = gamesArray[getVideoGameTitle];
            displayText(Norman);
        }
    }
    else {
        cout << "Library id empty. No video games to display." << endl;
    }
}