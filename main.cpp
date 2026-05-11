#include <iostream>
#include "DigitalMessage.h"

using namespace std;

int main()
{
    DigitalMessage mess("1011001");

    cout << "Original message: ";
    mess.show();
    cout << endl;

    return 0;
}