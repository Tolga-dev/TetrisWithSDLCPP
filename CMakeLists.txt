cmake_minimum_required(VERSION 3.23)
project(MakingTetris)


add_subdirectory(lib)

add_executable(MakingTetris main.cpp)

target_link_libraries(MakingTetris ${SDL2_LIBRARIES} SDL2_gfx GuiLib)


