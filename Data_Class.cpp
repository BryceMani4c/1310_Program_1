/*
FileName: Data_Class.cpp
Author:Cyrus Loyd
Created 9/17/24
Purpose: Functions for the VideoGame class. This class will store and manipulate video game data.
*/


#include <iostream>
#include <fstream>
#include "Text.h"
#include "Data_Class.h"

using namespace std;

VideoGame::VideoGame(Text* title, Text* dev, Text* pub, int rating, int year) {         //Creates the video game objects
    this->namePtr = title;
    this->devPtr = dev;
    this->pubPtr = pub;
    this->rat = rating;
    this->yr = year;
}

Text* VideoGame::getVideoGameTitle() const {                                            //Returns the name of the video game

    return this->namePtr;

}
Text* VideoGame::getDeveloper() const {                                                 //Returns the developer of the video game
    return this->devPtr;
}

Text* VideoGame::getPublisher() const {                                                 //Returns the publisher of the video game
    return this->pubPtr;
}

int VideoGame::getYearOfRelease() const {                                               //Returns the year the video game released
    return this->yr;
}

int VideoGame::getRating() const {                                                      //Returns the rating of the video game
    return this->rat;
}

// Setters

void VideoGame::setDeveloper(Text* developer) {
    if (this->devPtr != nullptr) {
        delete this->devPtr;  // Free old memory if necessary
    }
        this->devPtr = developer;
}

void VideoGame::setTitle(Text* title) {
    if (this->namePtr != nullptr) {
        delete this->namePtr;  // Free old memory if necessary
    }
        this->namePtr = title;
}

void VideoGame::setPublisher(Text* publisher) {
    if (this->pubPtr != nullptr) {
        delete this->pubPtr;  // Free old memory if necessary
    }
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

void VideoGame::printVideoGameDeets(){                                          //Prints the details of the video game (all stored info)

    cout<< "\nTitle: \t\t\t";
    namePtr->displayText();
    cout<< "\nDeveloper: \t\t";
    devPtr->displayText();
    cout<< "\nPublisher: \t\t";
    pubPtr->displayText();
    cout<< "\nRating: \t\t" << rat << "/100";
    cout<< "\nYear of Release: \t"<< yr << endl << endl; 
    return;
}

void VideoGame::printVidGameDeetsFile(ofstream& vidGamFile){                    //Saves the details of a video game to a file

    vidGamFile.open("TEXT_CASE.txt");
    vidGamFile<< "Title: " << namePtr->getText()<<endl;
    vidGamFile<< "Developer: " << devPtr->getText()<<endl;
    vidGamFile<< "Publisher: " << pubPtr->getText()<<endl;
    vidGamFile<< "Rating: " << rat << "/100";
    vidGamFile<< "Year of Release: "<< yr; 
    vidGamFile.close();
    return;

}
VideoGame::~VideoGame(){                                                        //Destroys the video game object

    delete this->namePtr;
    delete this->devPtr;
    delete this->pubPtr;
    return;
}