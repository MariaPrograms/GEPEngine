#pragma once
#ifndef Resource_H
#define Resource_H
#include <memory>
#include <string>

class Core;

//!  The Resource class. The parent class for all files that need to be loaded in.
/*!
This class is for information that needs to be loaded in from a file.
It's children include Shader, Mesh, Texture and Sound.
*/
class Resource
{
public:
	std::string path;//!This holds the path to the file for loading and cacheing purposes
	std::shared_ptr<Core> core;//!This is a refrence to Core for loading purposes

protected:
	virtual void Load(std::string _path) = 0;
};

#endif