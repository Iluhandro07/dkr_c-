#include <iostream>
#include "DigitalMessage.h"

using namespace std;

DigitalMessage::DigitalMessage()
{
    m_bits = 0;
    m_size = 0;
}

DigitalMessage::DigitalMessage(const char* bitString)
{
    m_bits = 0;
    m_size = 0;

    setFromString(bitString);
}

DigitalMessage::DigitalMessage(const DigitalMessage& other)
{
    m_size = other.m_size;

    if(m_size > 0)
    {
        m_bits = new int[m_size];

        for (size_t i = 0; i < m_size; i++)
        {
            m_bits[i] = other.m_bits[i];
        }
        
    }
    else
    {
        m_bits = 0;
    }
    
}

DigitalMessage::~DigitalMessage()
{
    delete[] m_bits;
}

DigitalMessage& DigitalMessage::operator=(const DigitalMessage& other)
{
    if(this != &other)
    {
        delete[] m_bits;

        m_size = other.m_size;

        if(m_size > 0)
        {
            m_bits = new int[m_size];
            for (size_t i = 0; i < m_size; i++)
            {
                m_bits[i] = other.m_bits[i];
            }
            
        }
        else
        {
            m_bits = 0;
        }
    }
    return *this;
}

void DigitalMessage::setFromString(const char* bitString)
{
    delete[] m_bits;

    m_size = strlen(bitString);
    m_bits = new int[m_size];

    for (int i = 0; i < m_size; i++)
    {
        if (bitString[i] == '1')
        {
            m_bits[i] = 1;
        }
        else
        {
            m_bits[i] = 0;
        }
    }
}

int DigitalMessage::getSize()
{
    return m_size;
}

int DigitalMessage::getBit(int index)
{
    if (index >= 0 && index < m_size)
    {
        return m_bits[index];
    }

    return 0;
}

void DigitalMessage::setBit(int index, int value)
{
    if (index >= 0 && index < m_size)
    {
        if (value == 0 || value == 1)
        {
            m_bits[index] = value;
        }
    }
}

void DigitalMessage::flipBit(int index)
{
    if (index >= 0 && index < m_size)
    {
        m_bits[index] = 1 - m_bits[index];
    }
}

void DigitalMessage::show()
{
    for (int i = 0; i < m_size; i++)
    {
        cout << m_bits[i];
    }
}

char* DigitalMessage::toString()
{
    char* result = new char[m_size + 1];

    for (int i = 0; i < m_size; i++)
    {
       result[i] = m_bits[i] + '0';
    }

    result[m_size] = '\0';

    return result;
}