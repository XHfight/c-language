#pragma once
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* str)
		:_str(new char[strlen(str)+1])
	{}
	String(const String& str)
	{
		
	}
private:
	char* _str;
};