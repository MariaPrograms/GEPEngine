#pragma once

//!This class is to make sure specific classes cannot be created more than once
class NonCopyable
{
public:
	NonCopyable() {};
	~NonCopyable() {};

private:
	NonCopyable(const NonCopyable &);
	NonCopyable& operator=(const NonCopyable &);
};