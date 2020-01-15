cmake_minimum_required(VERSION 2.6)
project(GEPENGINE)

include_directories(
  src
)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Font.cpp
  src/rend/Util.cpp
  src/rend/stb_truetype.h
)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()


add_library(GEPEngine
 	src/GEPEngine/Core.cpp
	src/GEPEngine/Input.cpp
	src/GEPEngine/Object.cpp
	src/GEPEngine/World.cpp
	src/GEPEngine/Screen.cpp
	src/GEPEngine/NonCopyable.cpp
	src/GEPEngine/Exception.cpp

	src/GEPEngine/Components.cpp
	src/GEPEngine/Camera.cpp
	src/GEPEngine/Light.cpp

	src/GEPEngine/Resources.cpp
	src/GEPEngine/Resource.cpp
	src/GEPEngine/Mesh.cpp
	src/GEPEngine/MeshRenderer.cpp
	src/GEPEngine/Materials.cpp
	src/GEPEngine/MaterialAttribute.cpp	
	src/GEPEngine/Shader.cpp
	
	src/GEPEngine/Texture.cpp
	src/GEPEngine/stb_image.h
	src/GEPEngine/RenderTexture.cpp

	src/GEPEngine/Sound.cpp
	src/GEPEngine/SoundSource.cpp
	
	src/GEPEngine/BoxCollider.cpp
	src/GEPEngine/StaticModelCollider.cpp
	src/GEPEngine/TriBox.cpp
	src/GEPEngine/Trigger.cpp

	src/GEPEngine/GUI.cpp
	src/GEPEngine/Button.cpp
	src/GEPEngine/Font.cpp
)

add_executable(sandbox
	src/Sandbox/main.cpp
	src/sandbox/Player.cpp
	src/sandbox/Planets.cpp
	src/sandbox/Movement.cpp
	src/sandbox/Menu.cpp
)

target_link_libraries(sandbox GEPEngine SDL2 rend OpenAL32)
