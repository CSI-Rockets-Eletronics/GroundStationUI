
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "VisualComponents/RelayStatuses.h"
#include "VisualComponents/Sensors.h"
#include "VisualComponents/ProgramStatusSymbol.h"
#include "DataComponents/FileReader.h"
#include "DataComponents/DataParser.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FRAMERATE = 120;

//Starts up SDL and creates window
bool init();

//Loads media and assets
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;


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
        gWindow = SDL_CreateWindow( "CSI Ground Station", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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

    //Load all the necessary media and assets here
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

int main( int argc, char* args[] )
{

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
            //Main loop quitting flag.
            bool quit = false;
            SDL_Event e;

            //Keeps track of the time spent between frames (in milliseconds) so that we can interpolate later
            int deltatime = 0;

            //Initialization of the components of program
            RelayStatuses myRelays = RelayStatuses(0,0,gRenderer);
            Sensors mySensors = Sensors(0, 200,gRenderer);
            FileReader myFileReader = FileReader(inputFileName);
            DataParser myDataParser = DataParser(34);
            ProgramStatusSymbol myProgramStatusSymbol = ProgramStatusSymbol(600,300,15.0,gRenderer);


            while( !quit )
            {

                startTime = (float) clock();

                //Handle events on queue
                //Like key presses and other inputs
                while( SDL_PollEvent( &e ) ){
                    //When the X button on the window is pressed to close the program or the OS asks it to be closed
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }//User presses a key
                    else if( e.type == SDL_KEYDOWN ){
                        //Handle that
                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );


                //Render the relays dashboard
                myRelays.update(myDataParser.getRelayStatus());
                myRelays.render();

                //Render the sensors dashboard
                mySensors.update(myDataParser.getSensorValues());
                mySensors.render();

                //cout<<myFileReader.getLastLine()<<endl;
                //Reads from the input file the latest line of data and decodes it
                myDataParser.updateLine(myFileReader.getLastLine());

                //Keeps rotating to show the status of the program
                //If this stops rotating, the program has stopped
                myProgramStatusSymbol.update(deltatime);
                myProgramStatusSymbol.render();

                //Update screen
                SDL_RenderPresent( gRenderer );

                //Management to cap the framerate and keep it constant at the specified framerate
                SDL_Delay((int) MAX((1000.0/FRAMERATE)-deltatime,0) );
                endTime = (float)  clock();
                deltatime = 1000*((endTime-startTime))/CLOCKS_PER_SEC; //Working with milliseconds here
                //CLOKS_PER_SEC Can vary from system to system
                //cout<<deltatime<<" " << CLOCKS_PER_SEC<<endl;
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}