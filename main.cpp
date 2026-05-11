#include <iostream>
#include "DigitalMessage.h"
#include "MessageProcessor.h"

using namespace std;

int main()
{
    DigitalMessage message("1011001");
    MessageProcessor processor;

    cout << "=== DKR OOP Variant 16 ===" << endl;
    cout << endl;

    cout << "Original message: ";
    message.show();
    cout << endl;

    cout << "Polynomial: ";
    processor.showPolynom();
    cout << endl;

    DigitalMessage crc = processor.calculateCRC(message);

    cout << "CRC-4: ";
    crc.show();
    cout << endl;

    DigitalMessage transmittedMessage = processor.addCRC(message);

    cout << "Transmitted message: ";
    transmittedMessage.show();
    cout << endl;

    cout << endl;
    cout << "Checking message without error..." << endl;

    if (processor.checkIntegrity(transmittedMessage))
    {
        cout << "Result: message is valid" << endl;
    }
    else
    {
        cout << "Result: error detected" << endl;
    }

    cout << endl;

    DigitalMessage errorMessage = processor.introduceError(transmittedMessage, 3);

    cout << "Message with one-bit error: ";
    errorMessage.show();
    cout << endl;

    cout << "Checking message with error..." << endl;

    if (processor.checkIntegrity(errorMessage))
    {
        cout << "Result: message is valid" << endl;
    }
    else
    {
        cout << "Result: error detected" << endl;
    }

    return 0;
}