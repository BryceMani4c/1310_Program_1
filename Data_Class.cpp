/*
FileName: Data_Class.cpp
Dri

*/


#include <iostream>
#include <fstream>
#include "Text.h"
#include "Data_Class.h"

using namespace std;

VideoGame::VideoGame(Text* title, Text* dev, Text* pub, int rating, int year) {
    this->namePtr = title;
    this->devPtr = dev;
    this->pubPtr = pub;
    this->rat = rating;
    this->yr = year;
}

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

void VideoGame::printVideoGameDeets(){

    cout<< "\nTitle: ";
    namePtr->displayText();
    cout<< "\nDeveloper: ";
    devPtr->displayText();
    cout<< "\nPublisher: ";
    pubPtr->displayText();
    cout<< "\nRating: " << rat << "/100";
    cout<< "\nYear of Release: "<< yr; 
    return;
}

void VideoGame::printVidGameDeetsFile(ofstream& vidGamFile){

    vidGamFile.open("TEXT_CASE.txt");
    vidGamFile<< "Title: " << namePtr->getText()<<endl;
    vidGamFile<< "Developer: " << devPtr->getText()<<endl;
    vidGamFile<< "Publisher: " << pubPtr->getText()<<endl;
    vidGamFile<< "Rating: " << rat << "/100";
    vidGamFile<< "Year of Release: "<< yr; 
    vidGamFile.close();
    return;

}
VideoGame::~VideoGame(){

    delete this->namePtr;
    delete this->devPtr;
    delete this->pubPtr;
    return;
}