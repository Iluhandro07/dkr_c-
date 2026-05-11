#include <iostream>
#include "MessageProcessor.h"
using namespace std;

MessageProcessor::MessageProcessor()
{
    m_polynomSize = 5;
    m_polynom[0] = 1;
    m_polynom[1] = 0;
    m_polynom[2] = 0;
    m_polynom[3] = 1;
    m_polynom[4] = 1;
}

DigitalMessage MessageProcessor::calculateCRC(DigitalMessage message)
{
    int crcSize = m_polynomSize - 1;
    int messageSize = message.getSize();
    int dataSize = messageSize + crcSize;

    int* data = new int[dataSize];

    for (size_t i = 0; i < messageSize; i++)
    {
        data[i] = message.getBit(i);
    }

    for (size_t i = messageSize; i < dataSize; i++)
    {
        data[i] = 0;
    }
    
    for (size_t i = 0; i < messageSize; i++)
    {
        if(data[i] == 1)
        {
            for (size_t j = 0; j < m_polynomSize; j++)
            {
                data[i + j] = data[i + j] ^ m_polynom[j];
            }
            
        }
    }

    char* crcString = new char[crcSize +1];
    
    for (size_t i = 0; i < crcSize; i++)
    {
        crcString[i] = data[messageSize + i] + '0';
    }
    
    crcString[crcSize] = '\0';

    DigitalMessage crc(crcString);

    delete[] data;
    delete[] crcString;

    return crc;
}

DigitalMessage MessageProcessor::addCRC(DigitalMessage message)
{
    DigitalMessage crc = calculateCRC(message);

    int messageSize = message.getSize();
    int crcSize = crc.getSize();
    int resultSize = messageSize + crcSize;

    char* resultString = new char[resultSize + 1];

    for (int i = 0; i < messageSize; i++)
    {
        resultString[i] = message.getBit(i) + '0';
    }

    for (int i = 0; i < crcSize; i++)
    {
        resultString[messageSize + i] = crc.getBit(i) + '0';
    }

    resultString[resultSize] = '\0';

    DigitalMessage result(resultString);

    delete[] resultString;

    return result;
}

bool MessageProcessor::checkIntegrity(DigitalMessage message)
{
    int crcSize = m_polynomSize - 1;
    int dataSize = message.getSize();

    if (dataSize < m_polynomSize)
    {
        return false;
    }

    int* data = new int[dataSize];

    for (int i = 0; i < dataSize; i++)
    {
        data[i] = message.getBit(i);
    }

    for (int i = 0; i <= dataSize - m_polynomSize; i++)
    {
        if (data[i] == 1)
        {
            for (int j = 0; j < m_polynomSize; j++)
            {
                data[i + j] = data[i + j] ^ m_polynom[j];
            }
        }
    }

    bool isCorrect = true;

    for (int i = dataSize - crcSize; i < dataSize; i++)
    {
        if (data[i] != 0)
        {
            isCorrect = false;
        }
    }

    delete[] data;

    return isCorrect;
}

DigitalMessage MessageProcessor::introduceError(DigitalMessage message, int index)
{
    DigitalMessage errorMessage = message;

    errorMessage.flipBit(index);

    return errorMessage;
}

void MessageProcessor::showPolynom()
{
    for (int i = 0; i < m_polynomSize; i++)
    {
        cout << m_polynom[i];
    }
}