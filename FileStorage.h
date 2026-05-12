#ifndef FILESTORAGE_H
#define FILESTORAGE_H
#include "DigitalMessage.h"

class FileStorage
{
    private:
    char* m_fileName;
    char m_key;

    public:
    FileStorage();
    FileStorage(const char* fileName, char key);
    FileStorage(const FileStorage& other);
    ~FileStorage();

    FileStorage& operator=(const FileStorage& other);

    void setFileName(const char* fileName);
    char* getFileName();
    void setKey(char key);
    char getKey();
    char* encrypt(const char* text);
    char* decrypt(const char* text);
    void saveMessage(DigitalMessage message);
    void clear();
};

#endif