g++ -std=c++17 -g main.cpp VisualComponents/Sensors.cpp VisualComponents/RelayStatuses.cpp VisualComponents/ProgramStatusSymbol.cpp  DataComponents/FileReader.cpp DataComponents/DataParser.cpp -ISDL2\include -LSDL2\lib -Wall -lSDL2_ttf -lSDL2main -lSDL2  -o mainLinux
