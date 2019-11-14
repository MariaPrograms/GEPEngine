#pragma once
#include <exception>
#include <string>

struct Exception : public std::exception
{
	Exception(const std::string& message);
	void checkForErr();
	virtual ~Exception() throw();
	virtual const char* what() const throw();


private:
	std::string message;

};
