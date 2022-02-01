//
// Created by victo on 1/31/2022.
//

#include "ProgramStatusSymbol.h"
#include <math.h>
using namespace std;

ProgramStatusSymbol::ProgramStatusSymbol(int inXPos,int inYPos, float inRadius, SDL_Renderer* inRenderer){
    xPos = inXPos;
    yPos = inYPos;
    radius = inRadius;
    renderer = inRenderer;
}
void ProgramStatusSymbol::render(){
    int xf = (int) (xPos + radius*cos(theta));
    int yf = (int) (yPos + radius*sin(theta));
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
    SDL_RenderDrawLine(renderer, xPos, yPos, xf, yf);
}
void ProgramStatusSymbol::update(int deltatime){
    theta = fmod(theta + 2*M_PI*frequency*(deltatime/1000.0), 2*M_PI);
}