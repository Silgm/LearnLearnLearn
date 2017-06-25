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
	WINAPI						_stdcall ��������Լ��, ������������ڶ�ջ�з��ú������õĻ�е����, �󲿷�

	HINSTANCE hInstance			Instance Handle ʵ�����
								��windows, ���ڱ�ʶĳЩ����

	HINSTANCE hPrevInstance
	LPSTR lpCmdLine				LP����ָ��, ��16λWindows�µĲ���, ����32λwindows����PSTR������ͬ
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

/*LRESULT ��һ��longֵ*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI UserMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND		hwnd;
	
	/************************************************************************/
	/* 
		MSG�ṹ��
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

	style			ָ���������ͣ����֡����񡱣�����·���������ʹ�ð�λ��������������
					style �������

					����			����
					CS_VREDRAW		�ƶ����ߵ������ڵĸ߶ȣ���ֱ����ʱ���ػ���������
					CS_HREDRAW		�ƶ����ߵ������ڵĿ�ȣ�ˮƽ����ʱ���ػ���������
					CS_DBLCLKS		���û�����ڴ�����˫��ʱ��������˫����Ϣ�����ڹ���
					CS_OWNDC		����ÿ������ʵ������һ��Ψһ�� DC��ע�⣬���������Ǻܷ��㣬������������ʹ�ã���Ϊÿ�� DC ��ԼҪռ 800 ���ֽڵ��ڴ棩
					CS_CLASSDC		�ô���������д���ʵ��������һ�������� DC
					CS_PARENTDC		1. ���Ӵ��ڵĲü��������õ������ڵ� DC ��ȥ�������Ӵ��ڱ�����ڸ������ϻ���������ע�⣬�����Ӵ��ڴ�ϵͳ�����л�ȡ DC��������ʹ�ø����ڵ� DC����
									2. ָ���÷��������ϵͳ����
					CS_NOCLOSE		��ֹϵͳ�˵��Ĺر�ѡ��
					CS_SAVEBITS		1.��λͼ��ʽ���汻�ô����ڵ�����Ļ���֣����������ƶ��Ժ�ϵͳ������øñ����λͼ�ָ���Ļ�ƶ�����Ӧ���֣��Ӷ�ϵͳ�����򱻸ô����ڵ��Ĵ��ڷ��� WM_PAINT ��Ϣ
									2. �����Զ��ڲ˵����͵Ĵ��ڱȽϺ��ʣ���Ϊ��ͨ���Ǽ�̵���ʾһ��֮�����ʧ
									3. ���ø����Խ�������ʾ�ô��ڵ�ʱ�䣬��Ϊ��ͨ��Ҫ�ȷ��䱣��λͼ���ڴ�
					CS_BYTEALIGNCLIENT	���ֽڱ߽��ϣ��� x �����ϣ���λ���ڵ��û������λ��
					CS_BYTEALIGNWINDOW	���ֽڱ߽��ϣ��� x �����ϣ���λ���ڵ�λ��
					CS_GLOBALCLASS		1. ������ CreateWindow �� CreateWindowEx ��������������ʱ�������� hInstance ������ע�ᴰ����ʱ���ݸ� RegisterClass �� hInstance ������ͬ
										2. �����ָ���÷���������� hInstance ������ͬ
				

	lpfnWndProc		ָ�����ڹ��̣������ǻص�������
	cbClsExtra		Ԥ���Ķ���ռ䣬һ��Ϊ 0
	cbWndExtra		Ԥ���Ķ���ռ䣬һ��Ϊ 0
	hInstance		Ӧ�ó����ʵ�����
	hIcon			Ϊ���л��ڸô�����Ĵ����趨һ��ͼ��
	hCursor			Ϊ���л��ڸô�����Ĵ����趨һ�����ָ��
	hbrBackground	ָ�����ڱ���ɫ
	lpszMenuName	ָ�����ڲ˵�
	lpszClassName	ָ����������

	*/
	/************************************************************************/
	WNDCLASS	wndclass;

	//	���崰����ṹ��WNDCLASS��->ע�ᴰ���ࣨRegisterClass��->�������ڣ�CreateWindow��->��ʾ����
	//		��ShowWindow��->���´��ڣ�UpdateWindow��->��Ϣѭ����GetMessage->TranslateMessage -
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

	//ͨ��wndclassע�ᴰ��
	if (!RegisterClass(&wndclass)) {
		MessageBoxPrintf(TEXT("����"), MB_OK | MB_ICONERROR, TEXT("���ڴ���ʧ��"));
		
		return EXIT_FAILURE;
	}
	/*
	hwnd = CreateWindow(
		szAppName,				// window
		TEXT("Hello Win32"),	// window caption
		WS_OVERLAPPEDWINDOW,	// window style
		CW_USEDEFAULT,			//���ڳ�ʼx����
		CW_USEDEFAULT,			//���ڳ�ʼy����
		CW_USEDEFAULT,			//��ʼx�᷽���С
		CW_USEDEFAULT,			//��ʼy�᷽���С
		DESKTOP_HANDLE,			//�����ھ��
		NULL,					//window �˵����
		hInstance,				//����ʵ�����, �������ھ��
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
	PAINTSTRUCT		ps;		//����
	RECT			rect;
	switch (message)
	{

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rect);
		
		DrawText(hdc, TEXT("Hello, Win32"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);

		return EXIT_SUCCESS;
		/*ע��WM_DESTROY��Ϊ��Ҫ, ��Ȼ��ʹ�����'X'Ҳ�����������*/
		
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
