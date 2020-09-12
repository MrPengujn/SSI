#include "Connection.h"

int timing{ 100 }, bhopDelay{ 20 };
bool bhopIsOn = false;

void bhop() {
    Sleep(bhopDelay);
        if (GetAsyncKeyState(0x20)) {
            keybd_event(0x20, MapVirtualKey(0x20, 0), 0, 0);
            Sleep(1);
            keybd_event(0x20, MapVirtualKey(0x20, 0), 2, 0);
            Sleep(bhopDelay);
        }
}

void macros() {

    while (true) {
        //Start/stop binded on " insert "
        if (GetAsyncKeyState(VK_INSERT)) {
            std::cout << "\a*** Script status - OFF" << std::endl;
            break;
        } //timing change binded on " - "
        else if (GetAsyncKeyState(VK_SUBTRACT)) {
            std::cout << "Current delay: " << timing << ", Type the desired timing (in miliseconds): ";
            std::cin >> timing;
        }
        else if (GetAsyncKeyState(VK_MULTIPLY)) {
            bhopIsOn = !bhopIsOn;
            std::cout << "\a*** Bhop status: ";
            if (bhopIsOn == true) {
                std::cout << "ON" << std::endl;
            }
            else if (bhopIsOn == false) {
                std::cout << "OFF" << std::endl;
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_ADD)) {
            std::cout << "Current bhop delay: " << bhopDelay << ", Type the desired delay (in miliseconds): ";
            std::cin >> bhopDelay;
        }
        //shoot binded on alt                       
        if (GetAsyncKeyState(0x12)) {
            keybd_event(0x01, MapVirtualKey(0x01, 0), 0, 0);
            Sleep(timing);
            keybd_event(0x01, MapVirtualKey(0x01, 0), KEYEVENTF_KEYUP, 0);
            Sleep(timing);
        }
        if (bhopIsOn == true) {
            bhop();
        }
    }

}