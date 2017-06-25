#include "stdafx.h"
#include "userMain.h"

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC 
#include <crtdbg.h>
#include "tool.h"

#endif

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	int returnVal = UserMain(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
#ifdef _DEBUG
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	MessageBoxPrintf(TEXT("调试信息:"), MB_OK | MB_ICONASTERISK, TEXT("内存泄露次数: %d\n"), _CrtDumpMemoryLeaks());
#endif // DEBUG

	return returnVal;
}
