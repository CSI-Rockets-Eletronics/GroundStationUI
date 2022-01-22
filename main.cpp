
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "RelayStatuses.h"
#include "Sensors.h"
#include "FileReader.h"
#include "DataParser.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SNAKE_LENGTH = 1000;
const int BLOCK_SIZE = 10;
const int FRAMERATE = 60;
const int SPEED = 40;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Resets the snake
void resetSnake(int snake[][2]);

void renderSnake(int snake[][2]);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;


//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
    //Initialization flag
    bool success = true;
    TTF_Init();
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    //gXOut = SDL_LoadBMP( "x.bmp" );
    //if( gXOut == NULL )
    //{
        //printf( "Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError() );
        //success = false;
    //}

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gXOut );
    gXOut = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    TTF_Quit();
    //Quit SDL subsystems
    SDL_Quit();
}
void resetSnake(double snake[][2]){
    for (int i = 0; i < SNAKE_LENGTH; i ++){
        snake[i][0] = NULL;
        snake[i][1] = NULL;
    }
    snake[0][0] = SCREEN_WIDTH/2.0;
    snake[0][1] = SCREEN_HEIGHT/2.0;
}

void renderSnake(double snake[][2]){
    int thickness = 2;
    //Render red filled quad
    for (int i = 0; i < SNAKE_LENGTH; i++){
        if (snake[i][0] != NULL){
            SDL_Rect borderRect = { (int) snake[i][0], (int) snake[i][1], BLOCK_SIZE, BLOCK_SIZE};
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
            SDL_RenderFillRect( gRenderer, &borderRect );
            SDL_Rect fillRect = { (int) snake[i][0] + thickness, (int) snake[i][1] + thickness, BLOCK_SIZE-(2*thickness), BLOCK_SIZE-(2*thickness)};
            SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
            SDL_RenderFillRect( gRenderer, &fillRect );
        }

    }


}

void genFood(int food[2]){
    int x =  0 + rand() % (SCREEN_WIDTH - 0);
    int y =  0 + rand() % (SCREEN_HEIGHT - 0);
    food[0] = x; food[1] = y;
}

void renderFood(int food[2]){
    SDL_Rect fillRect = { food[0], food[1] , BLOCK_SIZE, BLOCK_SIZE};
    SDL_SetRenderDrawColor( gRenderer, 0x00,0x00 , 0xFF, 0xFF );
    SDL_RenderFillRect( gRenderer, &fillRect );
}

void checkColision(int food[2], int snake[][2]){
     
}
int main( int argc, char* args[] )
{
    //Start up SDL and create window
    double snake[SNAKE_LENGTH][2];
    resetSnake(snake);
    int velocity[2] = {1,0};
    int food [2] = {NULL,NULL};
    genFood(food);
    //struct timeval stop, start;
    float startTime;
    float endTime;
    //Deal with command line arguments:
    string inputFileName = "outputUITESTREAL.txt";
    if (argc > 1){
        inputFileName = string(args[1]);
    }
    //do stuff

    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Define parts
            RelayStatuses myRelays = RelayStatuses(0,0,gRenderer);
            Sensors mySensors = Sensors(0, 200,gRenderer);
            int deltatime = 0;
            FileReader myFileReader = FileReader(inputFileName);
            DataParser myDataParser = DataParser(34);
            //While application is running
            while( !quit )
            {
                //mingw_gettimeofday(&start, NULL); //start time
                startTime = (float) clock();
                //Handle events on queue
                while( SDL_PollEvent( &e ) ){
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }//User presses a key
                    else if( e.type == SDL_KEYDOWN ){


                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );
                if (true){
                    double deltaD [2] = { velocity[0] * (deltatime/1000.0) * SPEED,velocity[1]*(deltatime/1000.0) * SPEED};

                    double difX = (snake[0][0] + deltaD[0]) - ((int) (snake[0][0] + deltaD[0]) % SCREEN_WIDTH);
                    double difY = (snake[0][1] + deltaD[1]) - ((int) (snake[0][1] + deltaD[1]) % SCREEN_HEIGHT);
                    if (abs(difX) > 1){
                        snake[0][0] = (double) ((int) (snake[0][0] + deltaD[0]) % SCREEN_WIDTH);
                    }
                    if (abs(difY) > 1){
                        snake[0][1] = (double) ((int) (snake[0][1] + deltaD[1]) % SCREEN_HEIGHT);
                    }
                    if (!(abs(difX) > 1) && !(abs(difY) > 1)){
                        snake[0][0] = (snake[0][0] + deltaD[0]);
                        snake[0][1] = (snake[0][1] + deltaD[1]);
                    }
                    //cout<<snake[0][0]<<" "<<snake[0][1]<<endl;


                    //Render Snake

                    renderSnake(snake);

                    //Render Food
                    renderFood(food);
                }


                //Render the relays
                myRelays.update(myDataParser.getRelayStatus());
                myRelays.render();

                //Render the sensors
                mySensors.update(myDataParser.getSensorValues());
                mySensors.render();
                //x
                //cout<<myFileReader.getLastLine()<<endl;
                myDataParser.updateLine(myFileReader.getLastLine());
                //Update screen
                SDL_RenderPresent( gRenderer );

                //Management to cap the framerate and keep it constant at the specified framerate
                SDL_Delay((int) MAX((1000/FRAMERATE)-deltatime,0) );
                //mingw_gettimeofday(&stop, NULL);
                endTime = (float)  clock();
                //deltatime = (int) stop.tv_usec - start.tv_usec;
                deltatime = 1000*((endTime-startTime))/CLOCKS_PER_SEC; //Working with milliseconds here
                //cout<<deltatime<<" " << CLOCKS_PER_SEC<<endl;
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}