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
	src/GEPEngine/MeshRenderer.cpp
	src/GEPEngine/Materials.cpp
	src/GEPEngine/MaterialAttribute.cpp	
	src/GEPEngine/NonCopyable.cpp
	src/GEPEngine/Exception.cpp
	src/GEPEngine/VertexBufferObject.cpp
	src/GEPEngine/VertexArrayObject.cpp
	src/GEPEngine/Shader.cpp
	src/GEPEngine/Camera.cpp
)

add_executable(sandbox
	src/Sandbox/main.cpp
	src/sandbox/TestScene.cpp
	src/sandbox/TriangleRenderer.cpp
)

target_link_libraries(sandbox GEPEngine SDL2 glew32 opengl32)
