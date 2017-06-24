#ifndef TOOL_H_
#define TOOL_H_

#include "stdafx.h"

#define DESKTOP_HANDLE NULL

/************************************************************************/
/* 
	! WIN32 !
	MessageBoxPrintf(WCHAR * szCaption, WCHAR * szFormat, ...)
	MessageBox打印函数, Unicode编码
	@szCaption	L"窗口名称"
	@uType		窗口类型, 例如0, MB_OK and so on .
	@szFormat	L"格式字符串"
	@...		参数列表与szFormat匹配
*/
/************************************************************************/
int CDECL MessageBoxPrintf(WCHAR * szCaption, UINT uType, WCHAR * szFormat, ...);


#endif
