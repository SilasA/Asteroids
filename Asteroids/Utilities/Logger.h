#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <map>

#include "Time.h"

// idk wtf to do with this
#define LOG_DIV "===================================================================================================="

// Type of log
enum class LogType {
    kError,		// If the program can't run
    kWarning,	// If the program can run but something might or has gone wrong
    kInfo,		// If the log is just for info i.e. Debugging
    kAll		// For global logs (Log to all files)
};

// For iteration over the log map
typedef std::map<std::string, std::ofstream>::iterator FItr_t;

// Summary:
//
class Logger
{
private:
    // Log dir
    std::string m_dir;

    // To create timestamps for each log
    Time time;

    // Map containing all log files with IDs
    std::map<std::string, std::ofstream> m_fsout;

    // Converts the enum log type to a string literal of the type
    // i.e. LogType::kError converts to "[ERROR]"
    std::string typetostr(LogType type);

    // Writes an already formatted string to all open log files
    void writetoall(std::string& log);

public:
    Logger(std::string dir);
    ~Logger();

    static std::shared_ptr<Logger> GetInstance(const char* dir = nullptr)
    {
        static std::shared_ptr<Logger> l = std::make_shared<Logger>(dir);
        return l;
    }

    // Adds a log file to the map
    // Returns if it was a success or not
    // NOTE: unsuccessful means either the stream couldn't be opened or the
    // ID already exists.
    bool AddLogger(std::string&& id, std::string&& filename);

    // Closes the IDed log file
    // returns if the 'to be closed' file exists and closure was successful
    bool CloseLogger(std::string& id);

    // Closes all log files
    void CloseAll();

    // Erases all closed log files
    void EraseAllClosed();

    // Closes all files then erases them
    void EraseAll();

    // Writes a log to the IDed file
    // NOTE: ID must be provided if the log isn't intended for all files
    bool WriteLog(LogType type, std::string&& tag, std::string&& content,
        std::string id = "");
};

typedef std::shared_ptr<Logger> pLog;

#endif // LOGGER_H
