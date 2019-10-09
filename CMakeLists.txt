cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

add_library(GEPEngine
 	src/GEPEngine/Core.cpp
	src/GEPEngine/Keyboard.cpp
	src/GEPEngine/Object.cpp
	src/GEPEngine/World.cpp
	src/GEPEngine/Components.cpp
)

add_executable(sandbox
	src/Sandbox/main.cpp
)

target_link_libraries(sandbox GEPEngine)
