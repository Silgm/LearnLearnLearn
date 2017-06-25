#include "tool.h"

#define MAX_BUFF_LENGTH	1024


int CDECL MessageBoxPrintf(_TCHAR * szCaption, _TCHAR uType, _TCHAR * szFormat, ...) {
	_TCHAR szBuffer[MAX_BUFF_LENGTH];
	va_list pArgList;
	va_start(pArgList, szFormat);
	_vstprintf_s(szBuffer, sizeof(szBuffer) / sizeof(_TCHAR),szFormat, pArgList);
	va_end(pArgList);
	return MessageBox(NULL, szBuffer, szCaption, uType);
}
