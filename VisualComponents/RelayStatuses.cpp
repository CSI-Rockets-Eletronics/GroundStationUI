//
// Created by victo on 11/22/2021.
//

#include "RelayStatuses.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>


RelayStatuses::RelayStatuses(int inXPos,int inYPos, SDL_Renderer* inRenderer){
    xPos = inXPos;
    yPos = inYPos;
    renderer = inRenderer;
    FC_LoadFont(this->fontSans, this->renderer, "Fonts/OpenSans-Regular.ttf",  fontSize, FC_MakeColor(0,0,0,255), TTF_STYLE_NORMAL);
    if( this->fontSans == NULL ){
        printf( "Failed to load sansFont! SDL_ttf Error: %s\n", TTF_GetError() );
    }
}


void RelayStatuses::free() {
    FC_FreeFont(fontSans);
}


void RelayStatuses::update(bool *values){

    relayValues = values;
}
void RelayStatuses::render(){
    // Keeps track of the relay being rendered in sequence instead of matrix form
    int index = 0;
    int xMessage,yMessage,wMessage,hMessage;
    // For each row
    for (int j = 0; j < 2 ; j++){
        // For each of the 3 relays in the row (up to a maximum of 5 in total)
        for (int i = 0; i < 3 && index < 5; i++){
            // Sets up the position of each sub component
            SDL_Rect fillRect = { (int) xPos + space + (this->statusWidth + this->space)*i,
                                  (int) yPos + space + (this->statusHeight + this->space)*j,
                                  this->statusWidth ,
                                  this->statusHeight};
            if (!relayValues[index]){
                SDL_SetRenderDrawColor( this->renderer, 0xFF, 0x00, 0x00, 0xFF ); // Red
            } else{
                SDL_SetRenderDrawColor( this->renderer, 0x00, 0xFF, 0x00, 0xFF ); // Green
            }
            SDL_RenderFillRect( this->renderer, &fillRect );

            xMessage = (int) xPos + 2*space+ (this->statusWidth + this->space)*i;  //controls the rect's x coordinate
            yMessage = (int) yPos + 4*space+ (this->statusHeight + this->space)*j; // controls the rect's y coordinte
            wMessage = this->statusWidth - 2*space; // controls the width of the rect
            hMessage = this->statusHeight - 2*space; // controls the height of the rect
            FC_Draw(fontSans, renderer,xMessage, yMessage,relayNames[index]);
            index++;
        }
    }
}
