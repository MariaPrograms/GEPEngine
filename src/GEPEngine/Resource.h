#pragma once
#ifndef Resource_H
#define Resource_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <rend/rend.h>

class Core;

class Resource
{
public:

protected:
	std::shared_ptr<Core> core;
};

#endif