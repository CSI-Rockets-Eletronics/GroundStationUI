g++ -std=c++17 -Ofast main.cpp VisualComponents/Sensors.cpp VisualComponents/RelayStatuses.cpp VisualComponents/ProgramStatusSymbol.cpp  DataComponents/FileReader.cpp DataComponents/DataParser.cpp SDL_FontCache/SDL_fontcache.cpp -ISDL2\include -LSDL2\lib -Wall -lmingw32 -lSDL2_ttf -lSDL2main -lSDL2  -o fastmain