//
// Created by victo on 11/23/2021.
//
#include<iostream>
#include<vector>
#include<sstream>
#include <string>
using namespace std;

#ifndef MAIN_CPP_DATAPARSER_H
#define MAIN_CPP_DATAPARSER_H


class DataParser {
    private:
        // 1- Oxidizer Filling Valve | 2 - Oxidizer Bleeding Valve | 3- PyroCutter | 4- PyroValve | 5 - Igniter
        bool relayStatus[5] = {false,false,false,false,false};
        // 1- Oxidizer Tank Pressure Tansducer | 2- Combustion Chamber Pressure Transducer | 3- Load Cell | 4 - Unidefined
        // 1- Psi | 2 - Psi | 3 - Newtons | 4 - Undefined
        // They come as micro units so divide by 10^6
        float sensorValues[4] = {0,0,0,0};
        bool isFiring=false;
        float cpuTime = 0;
        char extraStatus[4] = {0,0,0,0};
        vector<int> stationData;
        int standardSize = 34;
        unsigned long mCs[4] = {1,256, 65536 , 16777216}; //multiplyig constants
    public:
        void updateLine(string inFileLine);
        bool* getRelayStatus();
        float* getSensorValues();
        bool getIsFiring();
        float getCpuTime();
        char* getExtraStatus();
        DataParser(int stdSize);
};


#endif //MAIN_CPP_DATAPARSER_H
