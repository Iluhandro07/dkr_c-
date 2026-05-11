#ifndef DIGITALMESSAGE_H
#define DIGITALMESSAGE_H

class DigitalMessage
{
    private:
    int* m_bits;
    int m_size;

    public:
    DigitalMessage();
    DigitalMessage(const char* bitString);
    DigitalMessage(const DigitalMessage& other);
    ~DigitalMessage();

    DigitalMessage& operator=(const DigitalMessage& other);

    void setFromString(const char* bitString);
    int getSize();
    int getBit(int index);
    void setBit(int index, int value);
    void flipBit(int index);
    void show();

    char* toString();
};

#endif