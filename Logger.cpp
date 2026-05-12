#include <iostream>
#include <fstream>
#include <cstring>
#include "Logger.h"

using namespace std;

Logger::Logger()
{
    m_fileName = new char[strlen("data/log.txt") + 1];
    strcpy(m_fileName, "data/log.txt");

}

Logger::Logger(const char* fileName)
{
    m_fileName = new char[strlen(fileName) + 1];
    strcpy(m_fileName, fileName);
}

Logger::Logger(const Logger& other)
{
    m_fileName = new char[strlen(other.m_fileName) +1];
    strcpy(m_fileName, other.m_fileName);
}

Logger::~Logger()
{
    delete[] m_fileName;
}

Logger& Logger::operator=(const Logger& other)
{
    if(this != &other)
    {
        delete[] m_fileName;

        m_fileName = new char[strlen(other.m_fileName) + 1];
        strcpy(m_fileName, other.m_fileName);
    }
    return *this;
}

void Logger::setFileName(const char* fileName)
{
    delete[] m_fileName;

    m_fileName = new char[strlen(fileName) + 1];
    strcpy(m_fileName, fileName);
}

char* Logger::getFileName()
{
    return m_fileName;
}

void Logger::log(const char* text)
{
    ofstream file;

    file.open(m_fileName, ios::app);

    if(file.is_open())
    {
        file << text << endl;    
    }
    else
    {
        cout << "Log file was not opened" << endl;
    }
    file.close();
}

void Logger::clear()
{
    ofstream file;

    file.open(m_fileName, ios::trunc);

    if(!file.is_open())
    {
        cout << "Log file was now opened" << endl;
    }
    file.close();
}