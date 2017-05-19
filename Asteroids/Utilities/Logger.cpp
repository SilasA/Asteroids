#include "Logger.h"

#include <direct.h>

std::string Logger::typetostr(LogType type)
{
    switch (type)
    {
    case LogType::kAll:
        return "[ALL]";
        break;
    case LogType::kError:
        return "[ERROR]";
        break;
    case LogType::kInfo:
        return "[INFO]";
        break;
    case LogType::kWarning:
        return "[WARNING]";
        break;
    default:
        break;
    }
    return "[INFO]";
}

void Logger::writetoall(std::string& log)
{
    for (FItr_t it = m_fsout.begin(); it != m_fsout.end(); ++it)
    {
        if (!it->second.is_open()) continue;
        it->second << log << std::endl;
    }
}

Logger::Logger(std::string dir)
{
    m_dir = dir;
    _mkdir(m_dir.c_str());
}

Logger::~Logger()
{
    EraseAll();
}

bool Logger::AddLogger(std::string&& id, std::string&& filename)
{
    if (m_fsout.find(id) != m_fsout.end()) return true;
    m_fsout[id] = std::ofstream(m_dir + filename);
    if (m_fsout[id].is_open())			// Opening log with full time stamp
        m_fsout[id] << time.getDateTime() <<
        "LOG: Log file opened with ID: " << id << std::endl <<
        LOG_DIV << std::endl;
    return m_fsout[id].is_open();
}

bool Logger::CloseLogger(std::string& id)
{
    if (m_fsout.find(id) == m_fsout.end()) return false;
    m_fsout[id].close();
    return true;
}

void Logger::CloseAll()
{
    for (FItr_t it = m_fsout.begin(); it != m_fsout.end(); ++it)
        it->second.close();
}

void Logger::EraseAllClosed()
{
    std::vector<std::string>* tmpIDs = new std::vector<std::string>();
    // Record IDs to be erased because erasing them in this loop will cause errors
    for (FItr_t it = m_fsout.begin(); it != m_fsout.end(); it++)
    {
        if (!it->second.is_open())
            tmpIDs->push_back(it->first);
    }
    // Erase the recorded IDs
    for (std::string& id : *tmpIDs)
        m_fsout.erase(id);
    delete tmpIDs;
}

void Logger::EraseAll()
{
    CloseAll();
    EraseAllClosed();
}

bool Logger::WriteLog(LogType type, std::string&& tag, std::string&& content,
    std::string id)
{
    // FORMAT:
    // [HH:MM:SS][TYPE] TAG: CONTENT
    std::string str =
        time.getTime() +
        typetostr(type) +
        " " + tag + ": " +
        content;
    if (type == LogType::kAll)
        writetoall(str);
    else
    {
        if (!m_fsout[id].is_open()) return false;
        m_fsout[id] << str << std::endl;
    }
    return true;
}