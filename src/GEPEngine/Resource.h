#pragma once
#ifndef Resource_H
#define Resource_H

#include <vector>
#include <string>

class Core;

class Resource
{
public:
	friend class Resources;

private:
	std::shared_ptr<Core> core;
};

#endif