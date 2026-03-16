cmake_minimum_required(VERSION 4.1)
project(SESC_Core)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SESC_Core
        Cage.h
        Unit.cpp
        Unit.h
        Hero.cpp
        Hero.h
        main.cpp
        Dice.cpp
        Dice.h
        CombatClass.cpp
        Species.cpp
)
