#pragma once
#include <Windows.h>
#include <iostream>


VOID WINAPI SetConsole();
BOOL SetHook(DWORD dwRawAddr, DWORD dwTarAddr, SIZE_T szRawSize);