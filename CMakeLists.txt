cmake_minimum_required(VERSION 3.20)

project(CPP_Sandbox)

add_subdirectory(GameOfLife)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PROPERTY VS_STARTUP_PROJECT GameOfLife
)