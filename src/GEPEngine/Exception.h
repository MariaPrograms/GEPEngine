#pragma once
#include <exception>
#include <string>

//!  The Exception class for safty and catching exceptions
/*!
This class is used in code for safty.
You do not need to initalise this class enywhere only call it when you need to do any error catching.

Example...

	try
	{
		some code that may fail.
	}
	catch (Exception& e)
	{
		throw Exception("code failed");
	}
*/
struct Exception : public std::exception
{
	//!The Constuctor
	/*!
	This will be wait you use to when there is an error.
	The parametor message is a string that is what went wrong.
	*/
	Exception(const std::string& _message);
	void CheckForError();
	virtual ~Exception() throw();
	virtual const char* What() const throw();


private:
	std::string message;

};
