#include "VideoGame_Library.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

VideoGameLibrary::VideoGameLibrary(int maxGames) {
    this->maxGames = maxGames;
    this->numGames = 0;
    videoGamesArray = new VideoGame*[maxGames];
    for (int i = 0; i < maxGames; ++i) {
        videoGamesArray[i] = nullptr;
    }
}

void VideoGameLibrary::resizeVideoGameArray() {
    VideoGame** placeHolder = new VideoGame*[maxGames * 2];
    for (int count = 0; count < numGames; count++) {
        placeHolder[count] = videoGamesArray[count];
    }

    delete[] videoGamesArray;
    videoGamesArray = placeHolder;
    maxGames *= 2;
}

void VideoGameLibrary::loadVideoGamesFromFile(string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error: Unable to open the file!";
    }

    int exit = 0;
    string title, platform, genre, ageRating, line;
    int year, userRating;
    while (exit == 0) {
        try {
            std::string tempStr;

            getline(inputFile, tempStr);  // For title
            Text* titleText = new Text(tempStr.c_str(), tempStr.length());
            videoGamesArray[numGames]->setTitle(titleText);  // Use the setter

            getline(inputFile, tempStr);  // For developer
            Text* devText = new Text(tempStr.c_str(), tempStr.length());
            videoGamesArray[numGames]->setDeveloper(devText);  // Use the setter

            getline(inputFile, tempStr);  // For publisher
            Text* pubText = new Text(tempStr.c_str(), tempStr.length());
            videoGamesArray[numGames]->setPublisher(pubText);  // Use the setter

            inputFile >> year;  // Direct input for year and rating (not using getline here)
            inputFile >> userRating;

            videoGamesArray[numGames]->setYearOfRelease(year);  // Use setter
            videoGamesArray[numGames]->setRating(userRating);  // Use setter
        } catch (const invalid_argument& e) {
            exit = 1;
        }

        if (exit == 0) {
            cout << "\nVideo game was added to the video game library!\n";
            numGames++;
        }
    }
}

void VideoGameLibrary::removeVideoGameFromArray() {
    if (numGames <= 1) {
        cout << "\nThere must always be at least one video game in the library." << endl;
        return;
    } else {
        displayVideoGameTitles();
        int choice;
        cout << "\nEnter the number of the video game you wish to remove (1 to " << numGames << "); ";
        cin >> choice;

        for (int i = choice - 1; i < numGames - 1; i++) {
            videoGamesArray[i] = videoGamesArray[i + 1];
        }

        cout << "Game number " << choice << " has been removed";
    }
}

void VideoGameLibrary::saveToFile(string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cout << "Error: Unable to open the file!";
    } else {
        for (int i = 0; i < numGames; i++) {
            videoGamesArray[i]->printVidGameDeetsFile(outputFile);
        }
    }

    outputFile.close();

    cout << "All video games have been printed to " << filename << "." << endl;
}

VideoGameLibrary::~VideoGameLibrary() {
    for (int i = 0; i < numGames; i++) {
        delete videoGamesArray[i];  // Free memory for each video game
    }
    delete[] videoGamesArray;  // Then delete the array
    cout << "\nvideoGamesArray: released memory\n";
}

void VideoGameLibrary::addVideoGameToArray() {
    std::string tempStr;

    cout << "Title:\t" << endl;
    getline(cin, tempStr);
    Text* titleText = new Text(tempStr.c_str(), tempStr.length());

    cout << "Developer:\t" << endl;
    getline(cin, tempStr);
    Text* devText = new Text(tempStr.c_str(), tempStr.length());

    cout << "Publisher:\t" << endl;
    getline(cin, tempStr);
    Text* pubText = new Text(tempStr.c_str(), tempStr.length());

    cout << "Rating:\t" << endl;
    int rating;
    cin >> rating;

    cout << "Year of Release:\t" << endl;
    int year;
    cin >> year;

    // Check size and resize if necessary
    if (numGames < maxGames) {
        VideoGame* newGame = new VideoGame(titleText, devText, pubText, rating, year);
        videoGamesArray[numGames] = newGame;
        cout << "Video game added successfully" << endl;
    } else {
        cout << "Library is full. Resizing..." << endl;
        this->resizeVideoGameArray();
        addVideoGameToArray();
    }

    numGames++;
}

void VideoGameLibrary::displayVideoGames() {
    if (numGames > 0) {
        for (int i = 0; i < numGames; i++) {
            videoGamesArray[i]->printVideoGameDeets();
        }
    } else {
        cout << "Library is empty. No video games to display." << endl;
    }
}

void VideoGameLibrary::displayVideoGameTitles() {
    if (numGames > 0) {
        for (int i = 0; i < numGames; i++) {
            string Norman = videoGamesArray[i]->getVideoGameTitle()->getText();
            cout << Norman << endl;
        }
    } else {
        cout << "Library is empty. No video games to display." << endl;
    }
}
