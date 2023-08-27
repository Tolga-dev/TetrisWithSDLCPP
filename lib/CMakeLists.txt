PROJECT(GuiLib)

add_library(${PROJECT_NAME}
        include/Game.h src/Game.cpp
        include/Board.h src/Board.cpp
        include/Tertomino.h src/Tetromino.cpp
        include/Defines.h
        )

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} /usr/include/SDL2)

set(SOURCES 1init.cpp)


target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_gfx)

target_include_directories(${PROJECT_NAME} PUBLIC include)