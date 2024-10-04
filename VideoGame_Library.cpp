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

VideoGameLibrary::VideoGameLibrary(int maxGames){           //Constructs the library and sets the library size
    this->maxGames = maxGames;
    this->numGames = 0;
    videoGamesArray = new VideoGame*[maxGames];
    for (int i = 0; i < maxGames; ++i) {
        videoGamesArray[i] = nullptr;
    }
};

void VideoGameLibrary::resizeVideoGameArray(){                  //Changes the size of the library
    VideoGame** placeHolder = new VideoGame*[maxGames * 2];     //If the array isn't big enough, it'll double the size of it
    for (int count = 0; count < numGames; count++) {
        placeHolder[count] = videoGamesArray[count];            //Makes sure the video games currently in the library move to the new array
    }

    delete[] videoGamesArray;                                   //Clean up of the old array
    videoGamesArray = placeHolder;
    maxGames *= 2;
};

void VideoGameLibrary::loadVideoGamesFromFile(string& filename) {       //Loads video games from a text file
    ifstream inputFile(filename);
    if (!inputFile) {                                                   //Checking to make sure there is a file and that it's able to access it
        cout << "Error: Unable to open the file!" << endl;              //otherwise, lets user know there's an error
        return;
    }

    string title, dev, pub;
    int year, userRating;
    
    while (getline(inputFile, title)) {                                 //While the text file still has titles to be read
        getline(inputFile, dev);                                        //saves the data to temp variables
        getline(inputFile, pub);
        inputFile >> userRating;
        inputFile >> year;
        inputFile.ignore();  // Ignore the newline after reading the year

        // Dynamically create Text objects after reading the data from the file
        Text* titleText = new Text(title.c_str(), title.length());
        Text* devText = new Text(dev.c_str(), dev.length());
        Text* pubText = new Text(pub.c_str(), pub.length());

        // Create a new VideoGame object and add it to the array
        if (numGames >= maxGames) {
            resizeVideoGameArray();  // Resize if array is full
        }
        videoGamesArray[numGames] = new VideoGame(titleText, devText, pubText, userRating, year);       //Adds a new video game object
        numGames++;

        cout << "\n" << title << " was added to the video game library!" << endl;
    }

    inputFile.close();
}

void VideoGameLibrary::removeVideoGameFromArray() {                                                     //Removes a video game from the library
    if (numGames <= 1) {                                                                                //Checks for no video games
        cout << "\nThere must always be at least one video game in the library." << endl;
        return;
    } else {                                                                                            //otherwise, it'll display all games currently in the library
        displayVideoGameTitles();
        int choice;
        cout << "\nEnter the number of the video game you wish to remove (1 to " << numGames << "); ";  //Asks user how many games to be removed
        cin >> choice;

        if (choice < 1 || choice > numGames) {                                                          //Input validation
            cout << "Invalid choice." << endl;
            return;
        }

        // Delete the game at the selected index
        delete videoGamesArray[choice - 1];

        // Shift the array to the left
        for (int i = choice - 1; i < numGames - 1; i++) {
            videoGamesArray[i] = videoGamesArray[i + 1];
        }

        // Set the last pointer to nullptr
        videoGamesArray[numGames - 1] = nullptr;

        // Reduce the number of games
        numGames--;

        cout << "Game number " << choice << " has been removed." << endl;
    }
}

void VideoGameLibrary::saveToFile(string& filename) {                               //Saves the current library to a text file
    ofstream outputFile(filename); // Open in overwrite mode
    if (!outputFile) {                                                              //Checks to make sure the file exists and can be opened
        cout << "Error: Unable to open the file!" << endl;                          //then lets user know
        return;
    }

    // Loop through each video game and save the details to the file
    for (int i = 0; i < numGames; i++) {
        Text* title = videoGamesArray[i]->getVideoGameTitle();
        Text* developer = videoGamesArray[i]->getDeveloper();
        Text* publisher = videoGamesArray[i]->getPublisher();
        int rating = videoGamesArray[i]->getRating();
        int year = videoGamesArray[i]->getYearOfRelease();

        // Write the details of each game in the correct format
        outputFile << title->getText() << endl;
        outputFile << developer->getText() << endl;
        outputFile << publisher->getText() << endl;
        outputFile << rating << endl;
        outputFile << year << endl;
    }

    outputFile.close();  // Close the file after writing
    cout << "All video games have been saved to " << filename << "." << endl;
}


void VideoGameLibrary::addVideoGameToArray() {                                          //Adds a video game to the library
    string title, dev, pub;
    int yr, rat;

    if (numGames < maxGames) {                                                    //Checks to make sure there's room in the array
        cout << "\nTitle:\t\t";                                                     //Adds data from user to the library
        cin.ignore(); // Ensure to ignore any leftover input before getline
        getline(cin, title);

        cout << "Developer:\t";
        getline(cin, dev);

        cout << "Publisher:\t";
        getline(cin, pub);

        cout << "Rating:\t\t";
        cin >> rat;
        cin.ignore();  // Ignore remaining newline before next input

        cout << "Year:\t\t";
        cin >> yr;
        cin.ignore();

        // Dynamically create Text objects after the input
        Text* titleText = new Text(title.c_str(), title.length());
        Text* devText = new Text(dev.c_str(), dev.length());
        Text* pubText = new Text(pub.c_str(), pub.length());

        // Create a new VideoGame object and add it to the array
        VideoGame* newGame = new VideoGame(titleText, devText, pubText, rat, yr);
        videoGamesArray[numGames] = newGame;

        cout << "Video game added successfully" << endl;
        numGames++;
    } else {                                                                            //If there's no room, calls the resize function to double size of library
        cout << "Library is full. Resizing..." << endl;                               
        resizeVideoGameArray();
    }
}

VideoGameLibrary::~VideoGameLibrary() {                                                 //Destroys the library to free memory
    for (int i = 0; i < numGames; i++) {
        delete videoGamesArray[i];  // Free the memory for each VideoGame
    }
    delete[] videoGamesArray;  // Free the array itself
}

void VideoGameLibrary::displayVideoGames()                                              //Displays all video games and the details currently in the library
{
    if (numGames > 0) {                                                                 //Checks to make sure there are video games in the library
        for (int i = 0; i < numGames; i++) {
            cout << "\n";
            videoGamesArray[i]->printVideoGameDeets();  // Use i instead of numGames
        }
    }
    else {                                                                              //otherwise, informs user of issue
        cout << "Library is empty. No video games to display." << endl;
    }
}

void VideoGameLibrary::displayVideoGameTitles()                                         //Exact same as the last function but displays only the titles
{
    if(numGames > 0){                                                                   
        for (int i=0; i < numGames; i++){
            cout << "\n";
            videoGamesArray[i]->getVideoGameTitle()->displayText();
        }
    }
    else{
        cout << "Library is empty. No video games to display." << endl;
    }
}