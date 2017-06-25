#ifndef TOOL_H_
#define TOOL_H_

#include "stdafx.h"

#define DESKTOP_HANDLE NULL

/************************************************************************/
/* 
	! WIN32 !
	MessageBoxPrintf(WCHAR * szCaption, WCHAR * szFormat, ...)
	MessageBox��ӡ����, TCHAR��ʽ


	@szCaption	L"��������"
	@uType		��������, ����
						MB_OK	Ĭ��ֵ����һ����ȷ�ϡ���ť������
						MB_YESNO	�С��ǡ��͡���������ť������
						MB_ABORTRETRYIGNORE	�С���ֹ���������ԡ��͡�������������ť������
						MB_YESNOCANCEL	�С��ǡ������񡱺͡�ȡ����������ť������
						MB_RETRYCANCEL	�С����ԡ��͡�ȡ����������ť������
						MB_OKCANCEL	�С�ȷ�����͡�ȡ����������ť������

						//////////////////////////////////////////////////
						
						MB_ICONEXCLAMATION	һ����̾�ų�������Ϣ��

						MB_ICONWARNING	һ����̾�ų�������Ϣ��ͬ�ϣ�
						MB_ICONINFORMATION	һ��ԲȦ��Сд��ĸi��ɵ�ͼ���������Ϣ��

						MB_ICONASTERISK	һ��ԲȦ��Сд��ĸi��ɵ�ͼ���������Ϣ��ͬ�ϣ�
						MB_ICONQUESTION	һ��������ͼ���������Ϣ��

						MB_ICONSTOP	һ��ֹͣ��Ϣͼ���������Ϣ��

						MB_ICONERROR	һ��ֹͣ��Ϣͼ���������Ϣ��ͬ�ϣ�
						MB_ICONHAND	һ��ֹͣ��Ϣͼ���������Ϣ��ͬ�ϣ�


	@szFormat	L"��ʽ�ַ���"
	@...		�����б���szFormatƥ��

	@return		IDOK	�û������ˡ�ȷ�ϡ���ť
				IDCANCEL	�û������ˡ�ȡ������ť
				IDABORT	�û������ˡ���ֹ����ť
				IDRETRY	�û������ˡ����ԡ���ť
				IDIGNORE	�û������ˡ����ԡ���ť
				IDYES	�û������ˡ��ǡ���ť
				IDNO	�û������ˡ��񡱰�ť
*/
/************************************************************************/
int CDECL MessageBoxPrintf(_TCHAR * szCaption, _TCHAR uType, _TCHAR * szFormat, ...);


#endif
