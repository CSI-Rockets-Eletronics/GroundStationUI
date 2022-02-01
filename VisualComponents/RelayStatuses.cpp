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
}

void RelayStatuses::renderLegend() {

}

void RelayStatuses::update(bool *values){

    relayValues = values;
}
void RelayStatuses::render(){
    // Keeps track of the relay being rendered in sequence instead of matrix form
    int index = 0;

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
            // Opens a font style and sets a size
            if( this->Sans == NULL )
            {
                printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
            }
            // This is the color in rgb format,
            // Maxing out everything would give you the color white
            SDL_Color White = {255, 255, 255};

            // TTF_RenderText_Solid could only be used on
            // SDL_Surface then you have to create the surface first
            SDL_Surface* surfaceMessage = TTF_RenderText_Blended(this->Sans, relayNames[index], White);
            if( surfaceMessage == NULL )
            {
                printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
            }
            // Converts it into a texture
            SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
            SDL_Rect Message_rect; //create a rect
            Message_rect.x = xPos + 2*space+ (this->statusWidth + this->space)*i;  //controls the rect's x coordinate
            Message_rect.y = yPos + 2*space+ (this->statusHeight + this->space)*j; // controls the rect's y coordinte
            Message_rect.w = this->statusWidth - 2*space; // controls the width of the rect
            Message_rect.h = this->statusHeight - 2*space; // controls the height of the rect
            // (0,0) is on the top left of the window/screen,
            // X increases to the right, Y downwards

            // Now since it's a texture, you have to put RenderCopy
            // you put the renderer's name first, the Message,
            // the crop size (you can ignore this if you don't want
            // to dabble with cropping), and the rect which is the size
            // and coordinate of your texture

            SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

            // Frees the surface and texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(Message);


            index++;
        }
    }
}
