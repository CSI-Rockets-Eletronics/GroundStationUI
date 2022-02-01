//
// Created by victo on 11/23/2021.
//

#ifndef MAIN_CPP_FILEREADER_H
#define MAIN_CPP_FILEREADER_H

#include <string>
using namespace std;

class FileReader {
    private:
        string filename;
        int maxLoopCount = 1000;
    public:
        string getLastLine();
        FileReader(string inFileName);
};


#endif //MAIN_CPP_FILEREADER_H
