//
// Created by victo on 11/23/2021.
//
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "FileReader.h"
using namespace std;

FileReader::FileReader(string inFileName) {
    filename = inFileName;
}

string FileReader::getLastLine(){
    ifstream fin;
    try{
        fin.open(this->filename);
    } catch(...){
        cout << "An exception occurred in opening the file: " << this->filename << endl;
        cout <<"Try checking if the file exists in the specified directory (Default: the directory you are running this code from)"<<endl;
    }
    if(fin.is_open()) {
        //If the file ends in \n this should be -2, if it does not end in \n then do -1
        fin.seekg(-2,ios_base::end);                // go to two spot before the EOF

        bool keepLooping = true;
        int index = 0;
        while(keepLooping && index < maxLoopCount) {
            char ch;
            fin.get(ch);                            // Get current byte's data

            if((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
                fin.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if(ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
            index++;
        }
        if (index==maxLoopCount){
            return "";
        }
        string lastLine;
        getline(fin,lastLine);                      // Read the current line
        fin.close();
        return lastLine;
    } else {
        cout <<"An exception occurred in opening the file: " << this->filename << endl;
        cout <<"Try checking if the file exists in the specified directory (Default: the directory you are running this code from)"<<endl;
        exit(1);
    }

    return 0;
}