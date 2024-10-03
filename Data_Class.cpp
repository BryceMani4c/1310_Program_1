#include <iostream>
#include <fstream>
#include "Text.h"
#include "Data_Class.h"

using namespace std;

// Constructor
VideoGame::VideoGame(Text* title, Text* dev, Text* pub, int rating, int yr) {
    this->namePtr = title;
    this->devPtr = dev;
    this->pubPtr = pub;
    this->rat = rating;
    this->yr = yr;
}

// Destructor
VideoGame::~VideoGame() {
    delete this->namePtr;
    delete this->devPtr;
    delete this->pubPtr;
    cout << "Video Game Destructor called." << endl;
}

// Getter functions
Text* VideoGame::getVideoGameTitle() const {
    return this->namePtr;
}

Text* VideoGame::getDeveloper() const {
    return this->devPtr;
}

Text* VideoGame::getPublisher() const {
    return this->pubPtr;
}

int VideoGame::getYearOfRelease() const {
    return this->yr;
}

int VideoGame::getRating() const {
    return this->rat;
}

// Setter functions
void VideoGame::setTitle(Text* title) {
    this->namePtr = title;
}

void VideoGame::setDeveloper(Text* developer) {
    this->devPtr = developer;
}

void VideoGame::setPublisher(Text* publisher) {
    this->pubPtr = publisher;
}

void VideoGame::setYearOfRelease(int year) {
    this->yr = year;
}

void VideoGame::setRating(int rating) {
    if (rating >= 0 && rating <= 100) {
        this->rat = rating;
    } else {
        std::cout << "Invalid rating. Rating should be between 0 and 100." << std::endl;
    }
}

// Member functions
void VideoGame::printVideoGameDeets() {
    cout << "Title: ";
    namePtr->displayText();
    cout << "Developer: ";
    devPtr->displayText();
    cout << "Publisher: ";
    pubPtr->displayText();
    cout << "Rating: " << rat << "/100" << endl;
    cout << "Year of Release: " << yr << endl;
}

void VideoGame::printVidGameDeetsFile(ofstream& vidGamFile) {
    vidGamFile << "Title: " << namePtr->getText() << endl;
    vidGamFile << "Developer: " << devPtr->getText() << endl;
    vidGamFile << "Publisher: " << pubPtr->getText() << endl;
    vidGamFile << "Rating: " << rat << "/100" << endl;
    vidGamFile << "Year of Release: " << yr << endl;
}