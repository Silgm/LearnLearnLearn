#ifndef TOOL_H_
#define TOOL_H_

#include "stdafx.h"

#define DESKTOP_HANDLE NULL

/************************************************************************/
/* 
	! WIN32 !
	MessageBoxPrintf(WCHAR * szCaption, WCHAR * szFormat, ...)
	MessageBox打印函数, TCHAR形式


	@szCaption	L"窗口名称"
	@uType		窗口类型, 例如
						MB_OK	默认值，有一个“确认”按钮在里面
						MB_YESNO	有“是”和“否”两个按钮在里面
						MB_ABORTRETRYIGNORE	有“中止”，“重试”和“跳过”三个按钮在里面
						MB_YESNOCANCEL	有“是”，“否”和“取消”三个按钮在里面
						MB_RETRYCANCEL	有“重试”和“取消”两个按钮在里面
						MB_OKCANCEL	有“确定”和“取消”两个按钮在里面

						//////////////////////////////////////////////////
						
						MB_ICONEXCLAMATION	一个惊叹号出现在消息框：

						MB_ICONWARNING	一个惊叹号出现在消息框（同上）
						MB_ICONINFORMATION	一个圆圈中小写字母i组成的图标出现在消息框：

						MB_ICONASTERISK	一个圆圈中小写字母i组成的图标出现在消息框（同上）
						MB_ICONQUESTION	一个问题标记图标出现在消息框：

						MB_ICONSTOP	一个停止消息图标出现在消息框：

						MB_ICONERROR	一个停止消息图标出现在消息框（同上）
						MB_ICONHAND	一个停止消息图标出现在消息框（同上）


	@szFormat	L"格式字符串"
	@...		参数列表与szFormat匹配

	@return		IDOK	用户按下了“确认”按钮
				IDCANCEL	用户按下了“取消”按钮
				IDABORT	用户按下了“中止”按钮
				IDRETRY	用户按下了“重试”按钮
				IDIGNORE	用户按下了“忽略”按钮
				IDYES	用户按下了“是”按钮
				IDNO	用户按下了“否”按钮
*/
/************************************************************************/
int CDECL MessageBoxPrintf(_TCHAR * szCaption, _TCHAR uType, _TCHAR * szFormat, ...);


#endif
