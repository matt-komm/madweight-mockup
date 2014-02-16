#include "defs.hpp"

const char* concanate(const std::string str1, const std::string str2)
{
	std::string* ret= new std::string();
	(*ret)+=str1;
	(*ret)+=str2;
	return ret->c_str();
}

const char* toStr(int i)
{
	char* ret = new char[20];
	sprintf(ret,"%i",i);
	return ret;
}
