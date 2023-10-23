cmake_minimum_required(VERSION 3.0.0)
project(SDLTEST VERSION 0.1.0 LANGUAGES C CXX)

set (SDL2_DIR ./)

file(COPY bin/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY images/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)

set(
    SRCS
    main.cpp
    framework.cpp
    Asteroid.cpp
    FlyingObject.cpp
    Missile.cpp
    Spaceship.cpp
    Model.cpp
    View.cpp
    Controller.cpp
)

set(
    HEADER
    framework.hpp
    Asteroid.hpp
    Missile.hpp
    FlyingObject.hpp
    Missile.hpp
    Spaceship.hpp
    Model.hpp
    View.hpp
    Controller.hpp
        Menu.cpp
        Menu.hpp
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDLTEST ${SRCS} ${HEADER})
target_link_libraries(SDLTEST ${SDL2_LIBRARIES})
