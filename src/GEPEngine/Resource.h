#pragma once
#ifndef Resource_H
#define Resource_H
#include <memory>
#include <string>

class Core;

class Resource
{
public:
	std::string path;
	std::shared_ptr<Core> core;

protected:
	virtual void Load(std::string _path) = 0;
};

#endif