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
}
void Sensors::update(float *values){
    sensorValues = values;
}
void Sensors::render(){
    // For each Row
    for (int i = 0; i < 4; i++){
        SDL_Rect fillRect = {
                (int) xPos + space + (this->valueWidth+ this->space),
                (int) yPos + space + (this->valueHeight + this->space)*i,
                this->valueWidth ,
                this->valueHeight};
        SDL_SetRenderDrawColor( this->renderer, 0xF0, 0xF0, 0xF0, 0xFF );
        SDL_RenderFillRect( this->renderer, &fillRect );
        if( this->Sans == NULL )
        {
            printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        }
        // This is the color in rgb format,
        // Maxing out everything would give you the color white
        SDL_Color Black = {0, 0, 0};

        // TTF_RenderText_Solid could only be used on
        // SDL_Surface then you have to create the surface first
        // Rendering the title
        SDL_Surface* surfaceMessage = TTF_RenderText_Blended(this->Sans, sensorNames[i], Black);
        if( surfaceMessage == NULL )
        {
            printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        }
        // Converts it into a texture
        SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect Message_rect; //create a rect
        Message_rect.x = (int) space + xPos + (valueWidth-labelWidth)/2 ;  //controls the rect's x coordinate
        Message_rect.y = (int) yPos + (valueHeight-labelHeight)/2+ (this->valueHeight + this->space)*i; // controls the rect's y coordinte
        Message_rect.w = this->labelWidth; // controls the width of the rect
        Message_rect.h = this->labelHeight; // controls the height of the rect
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
        // Rendering the value:
        SDL_Surface* surfaceValue = TTF_RenderText_Blended(this->Sans, to_string( sensorValues[i]).c_str(), Black);
        SDL_Texture* ValueTexture = SDL_CreateTextureFromSurface(renderer, surfaceValue);
        SDL_Rect Value_rect; // Creates a rect
        Value_rect.x = (int) space + xPos + (valueWidth-labelWidth)/2 + valueWidth ;  //controls the rect's x coordinate
        Value_rect.y = (int) yPos + (valueHeight-labelHeight)/2+ (this->valueHeight + this->space)*i; // controls the rect's y coordinte
        Value_rect.w = this->labelWidth; // controls the width of the rect
        Value_rect.h = this->labelHeight; // controls the height of the rect
        //Renders it
        SDL_RenderCopy(renderer, ValueTexture, NULL, &Value_rect);

        SDL_FreeSurface(surfaceValue);
        SDL_DestroyTexture(ValueTexture);
    }
}
