#include "stdafx.h"
#include "userMain.h"

#include "tool.h"

int WINAPI UserMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	int cxScreen, cyScreen;
	LPWSTR wStr = (WCHAR *)malloc(sizeof(WCHAR) * 1024);
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	MessageBoxPrintf(L"ScrnSize", MB_OK, L"The screen is %d x %d", cxScreen, cyScreen);
	MessageBoxPrintf(L"Hello", MB_OK, L"Pi is %ls", L"3.1415926");
	free(wStr);
	return EXIT_SUCCESS;
}


