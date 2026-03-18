cmake_minimum_required(VERSION 4.1)
project(SESC_Core)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SESC_Core
        Units/Helpers/Cage.h
        Units/Unit.cpp
        Units/Unit.h
        Units/Hero.cpp
        Units/Hero.h
        main.cpp
        Units/Helpers/Dice.cpp
        Units/Helpers/Dice.h
        Units/Helpers/CombatClass.cpp
        Units/Helpers/Species.cpp
        Field.cpp
        #        Field.cpp
)
