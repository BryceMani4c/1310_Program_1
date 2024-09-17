// File Name:   Driver.cpp
// Author Name: Bryson Bargas
// Date:        09/17/2024
// Purpose:     Keeps tracks of your library of videoGames.

#include "Data_Class.h"
#include "Text.h"
#include "Storage_Class.h"
#include <iostream>
using namespace std;

int main(){
    
    int capacity;
    cout << "How many video Games can your library hold?\n";
    cin >> capacity;

    // add input to designate size for videogame library array

    int choice;
    string fileName;

    do{
        cout << "\nWhat Would you like to do?";
        cout << "\n1.  Load video Games from file.";
        cout << "\n2.  Save video Games to a file.";
        cout << "\n3.  Add a video Game.";
        cout << "\n4.  Remove a video Game.";
        cout << "\n5.  Display all video Games.";
        cout << "\n6.  Remove ALL video Games from this library and end program.";
        cout << "\nCHOOSE 1-6:  ";

        cin >> choice;
    
        switch(choice){
            case 1:
                cout << "\nWhat is the name of the file? (example.txt) :  ";
                cin >> fileName;
                gameLibrary->loadVideoGamesFromFile(fileName);
                break;
            case 2:
                gameLibrary->saveVideoGamestoFile();
                break;
            case 3:
                gameLibrary->addVideoGameToArray();
                break;
            case 4:
                gameLibrary->removeVideoGameFromArray();
                break;
            case 5:
                gameLibrary->displayVideoGames();
                break;
            case 6:

                break;
            default:
                cout << "\nThat is not a valid choice.\nCHOOSE 1-6:  ";
                break;
        }
    }while(choice != 6);

}