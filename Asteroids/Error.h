#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <string>


class Error
{
private:

	const std::string couldNotFindFile = "File could not be found: ";
	const std::string i;

	std::string errDecipher(int code);

protected:

	// For custom errors
	void err(std::string& e);
	void err(const std::string& e);

	// For errors in the pre-defined errors
	void err(int code);

	// For pre-defined missing file error
	void err(int code, std::string& fileName);
	void err(int code, const std::string& fileName);
};


#endif /* ERROR_H */