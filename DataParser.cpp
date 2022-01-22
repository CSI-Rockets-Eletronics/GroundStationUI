//
// Created by victo on 11/23/2021.
//

#include<iostream>
#include<vector>
#include<sstream>
#include <string>
#include "DataParser.h"
using namespace std;

void DataParser::updateLine(string inFileLine){
    vector<int> result;
    bool errorOccurredInReadingFile = false;
    try{
        stringstream s_stream(inFileLine); //create string stream from the string
        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            result.push_back(stoi(substr));
            //cout<<stoi(substr)<<"|";
        }
        //cout<<"Size: "<< result.size() << " StdSize: " << standardSize<<endl;
    } catch (...){
        cout << "An exception occurred in parsing the file: " << '\n';
    }

    if ((int) result.size() == standardSize && !errorOccurredInReadingFile){
        stationData = result;
        //cout<<"lol"<<endl;
        //cout<<stationData[5]<<endl;
        //i is our index as we loop through the bytes of the packet
        //j is the index of our current byte within the number
        //xxxPakcetIndex is the index of the current number within the packet (which contains many numbers)
        //Remember the ESP32 is little endian so smaller bytes come first
        try {
            cpuTime = 0;
            int i = 0;
            for (; i < 4; i++) {
                cpuTime += result[i] * mCs[i];
            }
            cpuTime = cpuTime / 1000000; // since it comes in micros
            // continues from before
            //cout<<"----"<<cpuTime<<"----"<<endl;
            fill(sensorValues, sensorValues + (sizeof(sensorValues) / sizeof(sensorValues[0])), 0);
            //cout<<"Sensor Values"<<endl;
            int sensorValuePacketIndex = 0;
            for (int j = 0; i < (4 * 4 + 4); i++) {
                sensorValues[sensorValuePacketIndex] += result[i] * mCs[j];
                j++; //index within the sensor value
                if (j == 4) {
                    j = 0;
                    sensorValues[sensorValuePacketIndex] =
                            sensorValues[sensorValuePacketIndex] / 1000; //since it comes in millis
                    //cout<<(float)sensorValues[sensorValuePacketIndex]<<endl;
                    sensorValuePacketIndex++;
                }
            }
            fill(relayStatus, relayStatus + (sizeof(relayStatus) / sizeof(relayStatus[0])), 0);
            //cout<<"Relay status"<<endl;
            for (int j = 0; i < (4 * 4 + 4 + 5); i++) {
                relayStatus[j] = (bool) result[i];
                //cout<<(int)relayStatus[j]<<endl;
                j++; //index within the sensor value
            }
            isFiring = (bool) result[i];
            i++;
            //cout<<"Firing State"<<endl;
            //cout<<(int) isFiring<<endl;
            fill(extraStatus, extraStatus + (sizeof(extraStatus) / sizeof(extraStatus[0])), 0);
            //cout<<"Extra status"<<endl;
            int extraStatusPacketIndex = 0;
            for (int j = 0; i < (4 * 4 + 4 + 5 + 1 + 4); i++) {
                extraStatus[extraStatusPacketIndex] = (bool) result[i];
                j++;
                if (j == 4) {
                    j = 0;
                    //cout<<(int)extraStatus[extraStatusPacketIndex]<<endl;
                    extraStatusPacketIndex++;
                }
            }
        } catch(...){
            cout << "An exception occurred in parsing the packet to physical quantities: " << '\n';
        }
    }
}
bool* DataParser::getRelayStatus() {
    return relayStatus;
}
float* DataParser::getSensorValues(){
    return sensorValues;
}
bool DataParser::getIsFiring(){
    return isFiring;
}
float DataParser::getCpuTime(){
    return cpuTime;
}
char* DataParser::getExtraStatus(){
    return extraStatus;
}
DataParser::DataParser(int stdSize){
    standardSize = stdSize;
}