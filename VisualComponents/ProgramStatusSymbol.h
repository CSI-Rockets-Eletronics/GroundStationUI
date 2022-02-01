//
// Created by victo on 1/31/2022.
//
#include <SDL2/SDL.h>
#ifndef MAIN_CPP_PROGRAMSTATUSSYMBOL_H
#define MAIN_CPP_PROGRAMSTATUSSYMBOL_H


class ProgramStatusSymbol {
    private:
        int xPos;
        int yPos;
        int radius;
        SDL_Renderer* renderer;
        float frequency = 1.0;
        float theta = 0;
    public:
        ProgramStatusSymbol(int inXPos,int inYPos, float radius, SDL_Renderer* inRenderer);
        void render();
        void update(int deltatime);
};


#endif //MAIN_CPP_PROGRAMSTATUSSYMBOL_H
