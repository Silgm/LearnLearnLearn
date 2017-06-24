#include "tool.h"

#define MAX_BUFF_LENGTH	1024

int CDECL MessageBoxPrintf(WCHAR * szCaption, UINT uType,WCHAR * szFormat, ...) {
	WCHAR szBuffer[MAX_BUFF_LENGTH];
	va_list pArgList;
	va_start(pArgList, szFormat);
	wvsprintf(szBuffer, szFormat, pArgList);
	va_end(pArgList);
	return MessageBox(NULL, szBuffer, szCaption, uType);
}
