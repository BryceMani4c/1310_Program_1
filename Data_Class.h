#ifndef DATA_CLASS_H
#define DATA_CLASS_H
#include <iostream>
#include <fstream>
#include "Text.h"

using namespace std;

class VideoGame {
    public:
        VideoGame(Text*, Text*, Text*, int, int);
        ~VideoGame();

        // Getters
        Text* getVideoGameTitle() const;
        Text* getDeveloper() const;
        Text* getPublisher() const;
        int getYearOfRelease() const;
        int getRating() const;

        // Setters
        void setDeveloper(Text* developer);
        void setTitle(Text* title);
        void setPublisher(Text* publisher);
        void setYearOfRelease(int year);
        void setRating(int rating);

        // Other functions
        void printVideoGameDeets();
        void printVidGameDeetsFile(ofstream&);

    private:
        Text* namePtr;
        Text* devPtr;
        Text* pubPtr;
        int yr;
        int rat;
};

#endif