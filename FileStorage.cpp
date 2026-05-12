#include <iostream>
#include <fstream>
#include <cstring>
#include "FileStorage.h"

using namespace std;

FileStorage::FileStorage()
{
    m_fileName = new char[strlen("data/encrypted_messages.txt") + 1];
    strcpy(m_fileName, "data/encrypted_messages.txt");
    m_key = 'K';
}

FileStorage::FileStorage(const char* fileName, char key)
{
    m_fileName = new char[strlen(fileName) + 1];
    strcpy(m_fileName, fileName);
    m_key = key;
}

FileStorage::FileStorage(const FileStorage& other)
{
    m_fileName = new char[strlen(other.m_fileName) + 1];
    strcpy(m_fileName, other.m_fileName);
    m_key = other.m_key;
}

FileStorage::~FileStorage()
{
    delete[] m_fileName;
}

FileStorage& FileStorage::operator=(const FileStorage& other)
{
    if(this != &other)
    {
        delete[] m_fileName;

        m_fileName = new char[strlen(other.m_fileName) + 1];
        strcpy(m_fileName, other.m_fileName);
        m_key = other.m_key;
    }
    return *this;
}

char* FileStorage::encrypt(const char* text)
{
    int length = strlen(text);
    char* encrypted = new char[length + 1];

    for (size_t i = 0; i < length; i++)
    {
        encrypted[i] = text[i] ^ m_key;
    }
    encrypted[length] = '\0';

    return encrypted;
}

char* FileStorage::decrypt(const char* text)
{
    return encrypt(text);
}

void FileStorage::saveMessage(DigitalMessage message)
{
    char* text = message.toString();
    char* encrypted = encrypt(text);

    ofstream file;
    file.open(m_fileName, ios::app);

    if (file.is_open())
    {
        file << encrypted << endl;
    }
    file.close();

    delete[] text;
    delete[] encrypted;
}

void FileStorage::clear()
{
    ofstream file;
    file.open(m_fileName, ios::trunc);
    file.close();
}

void FileStorage::setFileName(const char* fileName)
{
    delete[] m_fileName;
    m_fileName = new char[strlen(fileName) + 1];
    strcpy(m_fileName, fileName);
}

char* FileStorage::getFileName()
{
    return m_fileName;
}

void FileStorage::setKey(char key)
{
    m_key = key;
}

char FileStorage::getKey()
{
    return m_key;
}