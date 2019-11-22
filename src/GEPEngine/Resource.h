#pragma once
#ifndef Resource_H
#define Resource_H
#include <memory>
#include <string>

class Core;

class Resource
{
public:

protected:
	virtual void Load(std::string _path) = 0;
	std::shared_ptr<Core> core;
};

#endif