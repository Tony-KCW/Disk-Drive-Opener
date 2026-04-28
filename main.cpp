#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPSTR c, int s) {
    // 1. Simple, formal request to open
    int openRes = MessageBox(NULL, 
        "Would you like to proceed with opening the optical disc drive tray?", 
        "System Control", 
        MB_YESNO | MB_ICONQUESTION);

    if (openRes == IDYES) {
        // Command to trigger the ASUS spring eject
        MCIERROR errOpen = mciSendString("set cdaudio door open", NULL, 0, NULL);

        if (errOpen != 0) {
            MessageBox(NULL, 
                "System Error: No compatible optical disc drive has been detected on this workstation.", 
                "Hardware Error", 
                MB_OK | MB_ICONERROR);
        } else {
            // 2. Acknowledge the action is complete
            MessageBox(NULL, 
                "The optical disc drive tray has been successfully opened.", 
                "System Control", 
                MB_OK | MB_ICONINFORMATION);
        }
    }
    return 0;
}