#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define MAX_STR 100
//using namespace std;
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")


// ȫ�ֱ���:
HINSTANCE hInst;						// ��ǰʵ��
TCHAR szTitle[MAX_STR] = _TEXT("Console_Win Demo");		// �������ı�
TCHAR szWindowClass[MAX_STR] = _TEXT("Console_Win Demo");	// ����������

// �˴���ģ���а����ĺ�����ǰ������:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int _tmain(int argc, _TCHAR * argv[])
{
	HINSTANCE hInstance = NULL;
	int nCmdShow = SW_SHOW;					// �ñ���ȡֵ�μ�MSDN
	MSG msg;

	printf("Console_Win Demo\n\n");
	printf("================================\n\n");

	hInstance = GetModuleHandle(NULL);
	printf("hInstance: %d\n", hInstance);
	printf("hInstance->unused: %d\n\n", hInstance->unused);
	printf("================================\n\n");


	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��:
	if (!InitInstance(hInstance, nCmdShow)) {
		printf("Error in InitInstance()!\n");
		return FALSE;
	}
	// ����Ϣѭ��:
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}

//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC) WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = NULL;
	printf("MyRegisterClass()!\n");

	return RegisterClassEx(&wcex);
}

//
//   ����: InitInstance(HANDLE, int)
//
//   Ŀ��: ����ʵ����������������ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance;	// ��ʵ������洢��ȫ�ֱ�����

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
			    CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL,
			    hInstance, NULL);

	if (!hWnd) {
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	printf("InitInstance()!\n");

	return TRUE;
}

//
//  ����: WndProc(HWND, unsigned, WORD, LONG)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
			 LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {
	case WM_CREATE:
		printf("Hello! I'm a CONSOLE. The WINDOW is my baby.\n");
		break;

	case WM_COMMAND:
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		printf("Goodbye!\n\n");
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
