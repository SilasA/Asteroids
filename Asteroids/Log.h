//

#ifndef LOG_H
#define LOG_H


class Log
{

protected:

	// Write a custom log.
	void writeLog(std::string& log);

	// Writes if a file has been found. (Assumes found with overload)
	// PARAM filename: The name of the file that has or hasn't been found.
	// PARAM isFound: Whether the file has been found or not.
	void writeFileFoundLog(std::string& filename, bool isFound);
	void writeFileFoundLog(std::string& filename); 
	void writeFileFoundLog(const std::string& filename, bool isFound);


public:

	Log();

};


#endif /* LOG_H */