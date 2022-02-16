cmake_minimum_required(VERSION 3.20)
project(GUI)
set(CMAKE_CXX_STANDARD 17)


set(SDL2_INCLUDE_DIR SDL2/include)
set(SDL2_LIB_DIR SDL2/lib)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(GUI main.cpp VisualComponents/Sensors.cpp VisualComponents/RelayStatuses.cpp VisualComponents/ProgramStatusSymbol.cpp  DataComponents/FileReader.cpp DataComponents/DataParser.cpp SDL_FontCache/SDL_fontcache.cpp)
target_link_libraries(${PROJECT_NAME} mingw32 SDL2_ttf SDL2main SDL2 )