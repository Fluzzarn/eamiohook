// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <cstdio>
#include "eamiohook-inf.h"

Ceamiohookinf* eamiohook;


DWORD WINAPI eamiohook_init(LPVOID dll_instance) {
    eamiohook = new Ceamiohookinf();
    AllocConsole();
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

    do {
        if (GetAsyncKeyState(VK_F9))
            eamiohook->send_input();
        else if (GetAsyncKeyState(VK_F10))
            break;

        Sleep(100);
    } while (true);
    delete eamiohook;
    return TRUE;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )



{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(NULL, NULL, eamiohook_init, hModule, NULL, NULL);

    return TRUE;


}


