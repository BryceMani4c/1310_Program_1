// File Name:   Driver.cpp
// Author Name: Bryson Bargas
// Date:        09/17/2024
// Purpose:     Keeps tracks of your library of videoGames.

#include "VideoGame_Library.h"
#include "Text.h"
#include "Data_Class.h"
#include <iostream>
using namespace std;

int main(){
    
    int capacity;
    cout << endl << endl << "How many video Games can your library hold?\n";                            //Asks user what they want the size of their library to be (kinda redundant since it'll double in size if more games than space in the array is added but whatever)
    cin >> capacity;
    cin.ignore();

    int choice;
    string fileName;
    VideoGameLibrary gameLibrary(capacity);

    do{                                                                                 //Asks user what they want to do in the program
        cout << "\nWhat Would you like to do?";
        cout << "\n1.  Load video Games from file.";
        cout << "\n2.  Save video Games to a file.";
        cout << "\n3.  Add a video Game.";
        cout << "\n4.  Remove a video Game.";
        cout << "\n5.  Display all video Games.";
        cout << "\n6.  Remove ALL video Games from this library and end program." << endl;
        cout << "\nCHOOSE 1-6:  ";

        cin >> choice;
    
        switch(choice){
            case 1:                                                                     //Calls function to load video games from a file (see VideoGame_Library.cpp)
                cout << "\nWhat is the name of the file? (example.txt) :  ";
                cin >> fileName;
                gameLibrary.loadVideoGamesFromFile(fileName);
                break;
            case 2:
                cout << "\nWhat is the name of the file? (example.txt) :  ";            //Calls function to save video games to a file (again, see VideoGame_Library.cpp)
                cin >> fileName;
                gameLibrary.saveToFile(fileName);
                break;
            case 3:
                gameLibrary.addVideoGameToArray();                                      //Calls function to add video games to the library (you get the gist)
                break;
            case 4:
                gameLibrary.removeVideoGameFromArray();                                 //Calls a function to remove a video game from the library
                break;
            case 5:
                gameLibrary.displayVideoGames();                                        //Calls a function to display all video games
                break;
            case 6:
                break;
            default:
                cout << "\nThat is not a valid choice.\nCHOOSE 1-6:  ";                 //Input validation (most important part)
                break;
        }
    }while(choice != 6);
}