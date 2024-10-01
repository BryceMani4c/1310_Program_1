/*
FileName: Data_Class.cpp
Dri

*/


#include <iostream>
#include <fstream>
#include "Text.h"

using namespace std;

class VideoGame{



public:

VideoGame(Text *title, Text *dev, Text *pub, int rating, int yr){

this->devPtr = dev;
this->namePtr = title;
this->pubPtr = pub;
this->rat = rating;
this->yr = yr;
return;


}

~VideoGame(){

    delete this->namePtr;
    delete this->devPtr;
    delete this->pubPtr;
    cout << "Video Game Destructor called.";
    return;
}

Text* getVideoGameTitle() const {

    return this->namePtr;

}

void printVideoGameDeets(){

    cout<< "Title: ";
    namePtr->displayText();
    cout<< "Developer: ";
    devPtr->displayText();
    cout<< "Publisher: ";
    pubPtr->displayText();
    cout<< "Rating: " << rat << "/100";
    cout<< "Year of Release: "<< yr; 
    return;
}

void printVidGameDeetsFile(ofstream& vidGamFile){

    vidGamFile.open("TEXT_CASE.txt");
    vidGamFile<< "Title: " << namePtr->getText()<<endl;
    vidGamFile<< "Developer: " << devPtr->getText()<<endl;
    vidGamFile<< "Publisher: " << pubPtr->getText()<<endl;
    vidGamFile<< "Rating: " << rat << "/100";
    vidGamFile<< "Year of Release: "<< yr; 
    vidGamFile.close();
    return;

}

private:

    ofstream vidGamFile;
    Text* namePtr;
    Text* devPtr;
    Text* pubPtr;
    int yr;
    int rat;

};