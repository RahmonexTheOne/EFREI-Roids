cmake_minimum_required(VERSION 3.0.0)
project(EFREI-ROIDS VERSION 0.1.0 LANGUAGES C CXX)

set (SDL2_DIR ./)
set (SDL2_ttf_DIR ./include/SDL2_ttf-devel-2.20.2-VC/SDL2_ttf-2.20.2/cmake)


file(COPY bin/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY include/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/)
file(COPY lib/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lib/)
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY assets/fonts/montserratRegular.ttf DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(
    SRCS
        src/main.cpp
        src/framework.cpp
        src/Asteroid.cpp
        src/FlyingObject.cpp
        src/Missile.cpp
        src/Spaceship.cpp
        src/Model.cpp
        src/View.cpp
        src/Controller.cpp
        src/Menu.cpp
)

set(
    HEADER
        include/hpp/framework.hpp
        include/hpp/Asteroid.hpp
        include/hpp/Missile.hpp
        include/hpp/FlyingObject.hpp
        include/hpp/Missile.hpp
        include/hpp/Spaceship.hpp
        include/hpp/Model.hpp
        include/hpp/View.hpp
        include/hpp/Controller.hpp
        include/hpp/Menu.hpp
        src/GameOver.cpp
        include/hpp/GameOver.hpp
        src/Level.cpp
        include/hpp/Level.hpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)


add_executable(EFREI-ROIDS ${SRCS} ${HEADER})
target_link_libraries(EFREI-ROIDS ${SDL2_LIBRARIES} SDL2_ttf::SDL2_ttf )
