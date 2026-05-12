#include <iostream>
#include "DigitalMessage.h"
#include "MessageProcessor.h"
#include "Logger.h"
#include "FileStorage.h"

using namespace std;

int main()
{
    Logger logger;
    FileStorage storage;

    storage.clear();
    logger.clear();
    logger.log("Program started");

    DigitalMessage message("1011001");
    MessageProcessor processor;
    storage.saveMessage(message);

    logger.log("Original message created");

    cout << "=== DKR OOP Variant 16 ===" << endl;
    cout << endl;

    cout << "Original message: ";
    message.show();
    cout << endl;

    cout << "Polynomial: ";
    processor.showPolynom();
    cout << endl;

    DigitalMessage crc = processor.calculateCRC(message);

    logger.log("CRC calculated");

    cout << "CRC-4: ";
    crc.show();
    cout << endl;

    DigitalMessage transmittedMessage = processor.addCRC(message);
    storage.saveMessage(transmittedMessage);

    logger.log("CRC added to message");

    cout << "Transmitted message: ";
    transmittedMessage.show();
    cout << endl;

    cout << endl;
    cout << "Checking message without error..." << endl;

    if (processor.checkIntegrity(transmittedMessage))
    {
        logger.log("Message without error: valid");
        cout << "Result: message is valid" << endl;
    }
    else
    {
        logger.log("Message without error: error detected");
        cout << "Result: error detected" << endl;
    }

    cout << endl;

    DigitalMessage errorMessage = processor.introduceError(transmittedMessage, 3);
    storage.saveMessage(errorMessage);

    logger.log("One-bit error introduced");

    cout << "Message with one-bit error: ";
    errorMessage.show();
    cout << endl;

    cout << "Checking message with error..." << endl;

    if (processor.checkIntegrity(errorMessage))
    {
        logger.log("Message without error: valid");
        cout << "Result: message is valid" << endl;
    }
    else
    {
        logger.log("Message without error: error detected");
        cout << "Result: error detected" << endl;
    }

    return 0;
}