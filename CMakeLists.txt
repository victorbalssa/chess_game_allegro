cmake_minimum_required(VERSION 3.5)
project(chess_game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

set(SOURCE_FILES src/main.c src/jeux.c src/graphisme.c)
add_executable(chess_game ${SOURCE_FILES})

set(GCC_ALLEGRO_FLAGS "-lallegro_font -lallegro")
add_definitions(${GCC_ALLEGRO_FLAGS})

INCLUDE_DIRECTORIES(  /opt/homebrew/Cellar/allegro/5.2.8.0_2/include/ )
LINK_DIRECTORIES(  /opt/homebrew/Cellar/allegro/5.2.8.0_2/lib )

file(GLOB LIBRARIES "/opt/homebrew/Cellar/allegro/5.2.8.0_2/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(chess_game ${LIBRARIES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${ALLEGRO_LIBRARIES})
