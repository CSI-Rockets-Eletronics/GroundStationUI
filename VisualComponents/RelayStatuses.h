//
// Created by victo on 11/22/2021.
//
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <tuple>
#include "../SDL_FontCache/SDL_fontcache.h"
using namespace std;
#ifndef MAIN_CPP_RELAYSTATUSES_H
#define MAIN_CPP_RELAYSTATUSES_H


class RelayStatuses {
    private:
        int xPos;
        int yPos;
        int statusWidth = 100;
        int statusHeight = 70;
        int space = 5;
        int fontSize = 20;
        TTF_Font* Sans = TTF_OpenFont("Fonts/OpenSans-Regular.ttf", fontSize);
        FC_Font* fontSans = FC_CreateFont();

        SDL_Renderer* renderer;
        const char* const relayNames[5]  = {"Filling","Bleeding","PyroCutter","PyroValve","Igniter"};
        bool *relayValues;
    public:
        void render();
        RelayStatuses(int inXPos,int inYPos,SDL_Renderer* inRenderer);
        void update(bool values[5]);


    void free();
};


#endif //MAIN_CPP_RELAYSTATUSES_H
