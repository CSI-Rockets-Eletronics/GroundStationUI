cmake_minimum_required(VERSION 3.20)
project(GUI)
set(CMAKE_CXX_STANDARD 17)


set(SDL2_INCLUDE_DIR SDL2/include)
set(SDL2_LIB_DIR SDL2/lib)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(GUI main.cpp Sensors.cpp RelayStatuses.cpp FileReader.cpp DataParser.cpp)
target_link_libraries(${PROJECT_NAME} mingw32 SDL2_ttf SDL2main SDL2 )