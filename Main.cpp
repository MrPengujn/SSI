#include "Connection.h"


int main()
{ 
    MessageBoxA(NULL, "\t            Keybinds\n-------------------------------------------------\n- start / stop the script    -> INSERT <-\n- shoot\t\t\t->ALT<-\n- change the delay\t\t -> - <-\n- Toggle bhop ON / OFF        -> * <-\n- Change the bhop delay      -> + <-\n-------------------------------------------------\n\n-> Check the console for debugs\n-> Press OK to continue\n\n\t\tEnjoy!", "Simple script by Itsuki", MB_OK);

    while (true) {
        Sleep(100);
        if (GetAsyncKeyState(VK_INSERT)) {
            std::cout << "\a*** Script status - ON" << std::endl;
            Sleep(100);
            macros();
        }
    }
}
    