//
// Created by victo on 11/22/2021.
//

#include "Sensors.h"
#include <iostream>
using namespace std;

Sensors::Sensors(int inXPos,int inYPos, SDL_Renderer* inRenderer){
    xPos = inXPos;
    yPos = inYPos;
    renderer = inRenderer;
    FC_LoadFont(this->fontSans, this->renderer, "Fonts/OpenSans-Regular.ttf",  fontSize, FC_MakeColor(0,0,0,255), TTF_STYLE_NORMAL);
    if( this->fontSans == NULL ){
        printf( "Failed to load sansFont! SDL_ttf Error: %s\n", TTF_GetError() );
    }
}
void Sensors::update(float *values){
    sensorValues = values;
}
void Sensors::render(){
    int xMessageValue,yMessageValue;
    int xMessageLabel,yMessageLabel;
    // For each Row
    for (int i = 0; i < 4; i++){
        SDL_Rect fillRect = {
                (int) xPos + space + (this->valueWidth+ this->space),
                (int) yPos + space + (this->valueHeight + this->space)*i,
                this->valueWidth ,
                this->valueHeight};
        SDL_SetRenderDrawColor( this->renderer, 0xF0, 0xF0, 0xF0, 0xFF );
        SDL_RenderFillRect( this->renderer, &fillRect );

        xMessageLabel = (int) space + xPos + (valueWidth-labelWidth)/2 ;  //controls the rect's x coordinate
        yMessageLabel = (int) yPos + (valueHeight-labelHeight)/2+ (this->valueHeight + this->space)*i; // controls the rect's y coordinte
        FC_Draw(fontSans, renderer,xMessageLabel, yMessageLabel,sensorNames[i]);

        xMessageValue = (int) space + xPos + (valueWidth-labelWidth)/2 + valueWidth ;  //controls the rect's x coordinate
        yMessageValue = (int) yPos + (valueHeight-labelHeight)/2+ (this->valueHeight + this->space)*i; // controls the rect's y coordinte
        FC_Draw(fontSans, renderer,xMessageValue, yMessageValue,to_string( sensorValues[i]).c_str());
    }
}
void Sensors::free() {
    FC_FreeFont(fontSans);
}
