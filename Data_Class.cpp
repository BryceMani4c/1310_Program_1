#include <iostream>
#include <fstream>

using namespace std;

class VideoGame{



public:

VideoGame(Text *title, Text *dev, Text *pub, int rating, int yr){

this->devPtr = &dev;
this->namePtr = &title;
this->pubPtr = &pub;
this->rat = rating;
this->yr = yr;
return;


}

~VideoGame(){

    delete namePtr;
    delete devPtr;
    delete pubPtr;
    cout << "Video Game Destructor called.";
    return;
}

Text* VideoGame::getVideoGameTitle() const {

    return this->yr;

}

void VideoGame::printVideoGameDeets(){

    cout<< "Title: " << &namePtr<<endl;
    cout<< "Developer: " << &devPtr<<endl;
    cout<< "Publisher: " << &pubPtr<<endl;
    cout<< "Rating: " << rat << "/100";
    cout<< "Year of Release: "<< yr; 
    return;
}

void VideoGame::printVidGameDeetsFile(ofstream vidGamFile){

    vidGamFile.open("TEXT_CASE.txt");
    vidGamFile<< "Title: " << &namePtr<<endl;
    vidGamFile<< "Developer: " << &devPtr<<endl;
    vidGamFile<< "Publisher: " << &pubPtr<<endl;
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