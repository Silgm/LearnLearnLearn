#ifndef TOOL_H_
#define TOOL_H_

#include "stdafx.h"

#define DESKTOP_HANDLE NULL

/************************************************************************/
/* 
	! WIN32 !
	MessageBoxPrintf(WCHAR * szCaption, WCHAR * szFormat, ...)
	MessageBox��ӡ����, Unicode����
	@szCaption	L"��������"
	@uType		��������, ����0, MB_OK and so on .
	@szFormat	L"��ʽ�ַ���"
	@...		�����б���szFormatƥ��
*/
/************************************************************************/
int CDECL MessageBoxPrintf(WCHAR * szCaption, UINT uType, WCHAR * szFormat, ...);


#endif
