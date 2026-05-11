#ifndef MESSAGEPROCESSOR_H
#define MESSAGEPROCESSOR_H
#include "DigitalMessage.h"

class MessageProcessor
{
private:
    int m_polynom[5];
    int m_polynomSize;
public:
    MessageProcessor();

    DigitalMessage calculateCRC(DigitalMessage message);
    DigitalMessage addCRC(DigitalMessage message);
    bool checkIntegrity(DigitalMessage message);
    DigitalMessage introduceError(DigitalMessage message, int index);
    void showPolynom();
};

#endif