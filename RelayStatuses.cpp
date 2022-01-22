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
    int index = 0;
    for (int j = 0; j < 2 ; j++){
        for (int i = 0; i < 3 && index < 5; i++){
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
            //this opens a font style and sets a size
            if( this->Sans == NULL )
            {
                printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
            }
            // this is the color in rgb format,
            // maxing out all would give you the color white,
            // and it will be your text's color
            SDL_Color White = {255, 255, 255};
            SDL_Color Red = {255, 0, 0};
            // as TTF_RenderText_Solid could only be used on
            // SDL_Surface then you have to create the surface first
            SDL_Surface* surfaceMessage = TTF_RenderText_Blended(this->Sans, relayNames[index], White);
            if( surfaceMessage == NULL )
            {
                printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
            }
            // now you can convert it into a texture
            SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
            SDL_Rect Message_rect; //create a rect
            Message_rect.x = xPos + 2*space+ (this->statusWidth + this->space)*i;  //controls the rect's x coordinate
            Message_rect.y = yPos + 2*space+ (this->statusHeight + this->space)*j; // controls the rect's y coordinte
            Message_rect.w = this->statusWidth - 2*space; // controls the width of the rect
            Message_rect.h = this->statusHeight - 2*space; // controls the height of the rect
            // (0,0) is on the top left of the window/screen,
            // think a rect as the text's box,
            // that way it would be very simple to understand

            // Now since it's a texture, you have to put RenderCopy
            // in your game loop area, the area where the whole code executes

            // you put the renderer's name first, the Message,
            // the crop size (you can ignore this if you don't want
            // to dabble with cropping), and the rect which is the size
            // and coordinate of your texture
            SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
            // Don't forget to free your surface and texture
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(Message);


            index++;
        }
    }
}
