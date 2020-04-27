# CMake minimum 3.16
cmake_minimum_required(VERSION 3.16)

# C++ 17
set(CMAKE_CXX_STANDARD 17)

# HunterGate package manager
include("3rd/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
        SHA1 "5659b15dc0884d4b03dbd95710e6a1fa0fc3258d"
)

# Define project
project(sunwhysengine)

# SFML
hunter_add_package(SFML)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
set(SFML_STATIC_LIBRARIES TRUE)

# Lua
hunter_add_package(Lua)
find_package(Lua CONFIG REQUIRED)

# Sol2
add_subdirectory("3rd/sol2")

# Create executable
add_executable(sunwhysengine
        src/Main.cpp
        src/SunWhysEngine.cpp
        src/SunWhysEngine.h
        src/States/State.h
        src/States/GameManager.cpp
        src/States/GameManager.h
        src/States/State.cpp
        src/Behaviors/Behavior.cpp
        src/Behaviors/Behavior.h
        src/Wrappers/LuaWrappers.h
        src/Wrappers/LuaWrappers.cpp)

# Link libraries
target_link_libraries(sunwhysengine sfml-graphics Lua::lua_lib sol2::sol2)
