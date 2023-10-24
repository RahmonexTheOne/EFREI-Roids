cmake_minimum_required(VERSION 3.0.0)
project(EFREI-ROIDS VERSION 0.1.0 LANGUAGES C CXX)

set (SDL2_DIR ./)


file(COPY bin/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY include/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/)
file(COPY lib/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lib/)
file(COPY images/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)
file(COPY backgroundMusic.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

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
    Menu.cpp
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
    Menu.hpp
)

find_package(SDL2 REQUIRED)

add_executable(EFREI-ROIDS ${SRCS} ${HEADER})
target_link_libraries(EFREI-ROIDS ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} )
