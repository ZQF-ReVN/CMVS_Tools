#pragma once
#include <Windows.h>
#include <detours.h>
#include "DiBProcess.h"

extern BOOL g_isDebug_FileDump;

VOID DumpFile();