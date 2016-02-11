
#include "Error.h"


std::string Error::errDecipher(int code)
{
	if (code == 0) return couldNotFindFile;
}


void Error::err(std::string& e)
{
	std::cerr << e << std::endl;
}


void Error::err(int code)
{
	std::cerr << errDecipher(code) << std::endl;  // Or call overload
}


void Error::err(int code, std::string& fileName)
{
	if (code == 0)
		std::cerr << errDecipher(code) << fileName << std::endl;
}