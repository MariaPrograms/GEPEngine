cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(
  src
)

add_library(GEPEngine
 	src/GEPEngine/Core.cpp
	src/GEPEngine/Keyboard.cpp
	src/GEPEngine/Object.cpp
	src/GEPEngine/World.cpp
	src/GEPEngine/Components.cpp
	src/GEPEngine/Screen.cpp
	src/GEPEngine/MashRenderer.cpp
	src/GEPEngine/Materials.cpp
	src/GEPEngine/MaterialAttribute.cpp
)

add_executable(sandbox
	src/Sandbox/main.cpp
	src/sandbox/TestScene.cpp
)

target_link_libraries(sandbox GEPEngine)
