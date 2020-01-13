#pragma once
#ifndef Component_H
#define Component_H

#include <memory>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <exception>

class Object;
class Input;
class World;
class Core;
class Screen;
class GUI;
class Component
{
public:
	Component();
	~Component();
	friend class Object;
	std::shared_ptr<Input>  GetInput();
	std::shared_ptr<GUI>  GetGUI();
	std::shared_ptr<Object>  GetObject();
	std::shared_ptr<World>  GetWorld();
	std::shared_ptr<Screen>  GetScreen();
	std::shared_ptr<Core>  GetCore();

protected:
	virtual void OnInit() {};
	virtual void OnStart() {};
	virtual void OnUpdate() {};
	virtual void OnDisplay() {};
	virtual void OnGUI() {};
	std::weak_ptr<Object> object;
};

#endif // Component_H
