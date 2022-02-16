//
// Created by victo on 11/23/2021.
//
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../SDL_FontCache/SDL_fontcache.h"

#ifndef MAIN_CPP_SENSORS_H
#define MAIN_CPP_SENSORS_H


class Sensors {
    private:
        int xPos;
        int yPos;
        int valueWidth = 150;
        int valueHeight = 70;
        int labelWidth = 150;
        int labelHeight = 50;
        int space = 5;
        int fontSize = 20;
        FC_Font* fontSans = FC_CreateFont();
        //this opens a font style and sets a size
        TTF_Font* Sans = TTF_OpenFont("Fonts/OpenSans-Regular.ttf", fontSize);
        SDL_Renderer* renderer;
        const char* const sensorNames[4]  = {"Oxidizer (psi)","Combustion (psi)","Load (N)","Undefined"};
        float *sensorValues;
    public:
        void render();
        Sensors(int inXPos,int inYPos,SDL_Renderer* inRenderer);
        void update(float values[4]);

    void free();
};


#endif //MAIN_CPP_SENSORS_H
