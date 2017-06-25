#include "stdafx.h"
#include "userMain.h"

#include "tool.h"

#define CHAP03

#ifndef CHAP03

/************************************************************************/
/* 
UserMain Will be call in WinMain!
*/
/************************************************************************/

/************************************************************************/
/* 
	WINAPI						_stdcall 函数调用约定, 表明如何生成在堆栈中放置函数调用的机械代码, 大部分

	HINSTANCE hInstance			Instance Handle 实例句柄
								在windows, 用于标识某些东西

	HINSTANCE hPrevInstance
	LPSTR lpCmdLine				LP代表长指针, 是16位Windows下的产物, 但在32位windows下与PSTR含义相同
	int nShowCmd				
*/
/************************************************************************/

#define TEMP_STRING_SIZE	1024

int WINAPI UserMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	int cxScreen, cyScreen;
	_TCHAR *tStr = (_TCHAR *)malloc(sizeof(_TCHAR) * TEMP_STRING_SIZE);
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	MessageBoxPrintf(TEXT("ScrnSize"), MB_OKCANCEL | MB_ICONASTERISK | MB_DEFBUTTON2, L"The screen is %d x %d", cxScreen, cyScreen);
	_stprintf_s(tStr, TEMP_STRING_SIZE, TEXT("%d"), 30);
	MessageBoxPrintf(TEXT("Hello"), MB_OK, TEXT("Pi is %ls"), tStr);

	free(tStr);

	return EXIT_SUCCESS;
}

#endif

/*LRESULT 是一个long值*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI UserMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND		hwnd;
	
	/************************************************************************/
	/* 
		MSG结构体
		hwnd
			Type: HWND
			A handle to the window whose window procedure receives the message. This member is NULL when the message is a thread message.
		message
			Type: UINT
			The message identifier. Applications can only use the low word; the high word is reserved by the system.
		wParam
			Type: WPARAM
			Additional information about the message. The exact meaning depends on the value of the message member.
		lParam
			Type: LPARAM
			Additional information about the message. The exact meaning depends on the value of the message member.
		time
			Type: DWORD
			The time at which the message was posted.
		pt
			Type: POINT
			The cursor position, in screen coordinates, when the message was posted.
	*/
	/************************************************************************/
	MSG			msg;

	/************************************************************************/
	/* 
	WNDCLASS

	style			指定窗口类型，各种“类风格”（详见下方↓）可以使用按位或操作符组合起来
					style 类风格解析

					类风格			含义
					CS_VREDRAW		移动或者调整窗口的高度（垂直方向）时，重绘整个窗口
					CS_HREDRAW		移动或者调整窗口的宽度（水平方向）时，重绘整个窗口
					CS_DBLCLKS		当用户光标在窗口内双击时，允许发送双击消息给窗口过程
					CS_OWNDC		给予每个窗口实例分配一个唯一的 DC（注意，尽管这样是很方便，但它必须慎重使用，因为每个 DC 大约要占 800 个字节的内存）
					CS_CLASSDC		该窗口类的所有窗口实例都共享一个窗口类 DC
					CS_PARENTDC		1. 将子窗口的裁剪区域设置到父窗口的 DC 中去，这样子窗口便可以在父窗口上绘制自身。（注意，这是子窗口从系统缓存中获取 DC，而不是使用父窗口的 DC。）
									2. 指定该风格可以提高系统性能
					CS_NOCLOSE		禁止系统菜单的关闭选项
					CS_SAVEBITS		1.以位图形式保存被该窗口遮挡的屏幕部分，当给窗口移动以后，系统便可以用该保存的位图恢复屏幕移动的相应部分，从而系统不用向被该窗口遮挡的窗口发送 WM_PAINT 消息
									2. 该特性对于菜单类型的窗口比较合适，因为它通常是简短的显示一下之后便消失
									3. 设置该特性将增加显示该窗口的时间，因为它通常要先分配保存位图的内存
					CS_BYTEALIGNCLIENT	在字节边界上（在 x 方向上）定位窗口的用户区域的位置
					CS_BYTEALIGNWINDOW	在字节边界上（在 x 方向上）定位窗口的位置
					CS_GLOBALCLASS		1. 当调用 CreateWindow 或 CreateWindowEx 函数来创建窗口时允许它的 hInstance 参数和注册窗口类时传递给 RegisterClass 的 hInstance 参数不同
										2. 如果不指定该风格，则这两个 hInstance 必须相同
				

	lpfnWndProc		指定窗口过程（必须是回调函数）
	cbClsExtra		预留的额外空间，一般为 0
	cbWndExtra		预留的额外空间，一般为 0
	hInstance		应用程序的实例句柄
	hIcon			为所有基于该窗口类的窗口设定一个图标
	hCursor			为所有基于该窗口类的窗口设定一个鼠标指针
	hbrBackground	指定窗口背景色
	lpszMenuName	指定窗口菜单
	lpszClassName	指定窗口类名

	*/
	/************************************************************************/
	WNDCLASS	wndclass;

	//	定义窗口类结构（WNDCLASS）->注册窗口类（RegisterClass）->创建窗口（CreateWindow）->显示窗口
	//		（ShowWindow）->更新窗口（UpdateWindow）->消息循环（GetMessage->TranslateMessage -
	//> DispatchMessage
	
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wndclass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	wndclass.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	//通过wndclass注册窗体
	if (!RegisterClass(&wndclass)) {
		MessageBoxPrintf(TEXT("错误"), MB_OK | MB_ICONERROR, TEXT("窗口创建失败"));
		
		return EXIT_FAILURE;
	}
	/*
	hwnd = CreateWindow(
		szAppName,				// window
		TEXT("Hello Win32"),	// window caption
		WS_OVERLAPPEDWINDOW,	// window style
		CW_USEDEFAULT,			//窗口初始x坐标
		CW_USEDEFAULT,			//窗口初始y坐标
		CW_USEDEFAULT,			//初始x轴方向大小
		CW_USEDEFAULT,			//初始y轴方向大小
		DESKTOP_HANDLE,			//父窗口句柄
		NULL,					//window 菜单句柄
		hInstance,				//窗口实例句柄, 即本窗口句柄
		NULL					// creation parameters
	);
	*/
	hwnd = CreateWindowEx(
		0,
		szAppName,
		TEXT("Hello Win32"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		DESKTOP_HANDLE,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC				hdc;
	PAINTSTRUCT		ps;		//画笔
	RECT			rect;
	switch (message)
	{

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rect);
		
		DrawText(hdc, TEXT("Hello, Win32"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);

		return EXIT_SUCCESS;
		/*注意WM_DESTROY极为重要, 不然即使点击了'X'也不会结束进程*/
		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return EXIT_SUCCESS;
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
