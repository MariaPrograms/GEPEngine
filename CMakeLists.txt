cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(
  src
  stb_image.h
)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()


add_library(GEPEngine
 	src/GEPEngine/Core.cpp
	src/GEPEngine/Keyboard.cpp
	src/GEPEngine/Object.cpp
	src/GEPEngine/World.cpp

	src/GEPEngine/Components.cpp

	src/GEPEngine/Screen.cpp
	src/GEPEngine/Camera.cpp
	
	src/GEPEngine/NonCopyable.cpp
	src/GEPEngine/Exception.cpp

	src/GEPEngine/Resources.cpp
	src/GEPEngine/Resource.cpp
	src/GEPEngine/Mesh.cpp
	src/GEPEngine/MeshRenderer.cpp
	src/GEPEngine/Materials.cpp
	src/GEPEngine/MaterialAttribute.cpp	
	src/GEPEngine/Shader.cpp
	src/GEPEngine/Texture.cpp
	src/GEPEngine/RenderTexture.cpp
)

add_executable(sandbox
	src/Sandbox/main.cpp
	src/sandbox/TestScene.cpp
)

target_link_libraries(sandbox GEPEngine SDL2 rend)
