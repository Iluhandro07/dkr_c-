#ifndef LOGGER_H
#define LOGGER_H
using namespace std;

class Logger
{
    private:
    char* m_fileName;

    public:
    Logger();
    Logger(const char* fileName);
    Logger(const Logger& other);
    ~Logger();

    Logger& operator=(const Logger& other);

    void setFileName(const char* fileName);
    char* getFileName();

    void log(const char* text);
    void clear();

};

#endif