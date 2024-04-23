// eamiohook-inf.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "eamiohook-inf.h"
#include <cstdio>

#ifndef DIK_KEYS
#define DIK_KEYS true
#define DIK_NUMPAD3         0x51
#endif // !DIK_KEYS



// This is an example of an exported variable
EAMIOHOOKINF_API int neamiohookinf=0;

// This is an example of an exported function.
EAMIOHOOKINF_API int fneamiohookinf(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Ceamiohookinf::Ceamiohookinf()
{
    return;
}

void Ceamiohookinf::send_input() {
    printf("Sending Key VK_NUMPAD3");
    INPUT inputs[2] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wScan = DIK_NUMPAD3;
    inputs[0].ki.dwFlags = KEYEVENTF_SCANCODE;


    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wScan = DIK_NUMPAD3;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;

    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    if (uSent != ARRAYSIZE(inputs))
    {
        printf("SendInput failed: 0x%x\n", HRESULT_FROM_WIN32(GetLastError()));
    }
}
