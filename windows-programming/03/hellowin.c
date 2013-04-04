/*------------------------------------------------------------------------
   	HELLOWIN.C -- Displays "Hello, Windows 98!" in client area
		      (c) Charles Petzold, 1998
                    这也就是说视窗讯息处理程式必须是可重入的.
 -----------------------------------------------------------------------*/

#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int g_iCmdShow;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		   PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND hwnd, hwnd2;
	MSG msg;
	WNDCLASS wndclass;

	g_iCmdShow = iCmdShow;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	if (!RegisterClass(&wndclass)) {
		MessageBox(NULL, TEXT("This program requires Windows NT!"),
			   szAppName, MB_ICONERROR);
		return 0;
	}
	hwnd = CreateWindow(szAppName,	// window class name
			    TEXT("The Hello Program"),	// window caption
			    WS_OVERLAPPEDWINDOW,	// window style
			    CW_USEDEFAULT,	// initial x position
			    CW_USEDEFAULT,	// initial y position
			    CW_USEDEFAULT,	// initial x size
			    CW_USEDEFAULT,	// initial y size
			    NULL,	// parent window handle
			    NULL,	// window menu handle
			    hInstance,	// program instance handle
			    NULL);	// creation parameters


	hwnd2 = CreateWindow(szAppName,	// window class name
			     TEXT("The Hello Program"),	// window caption
			     WS_OVERLAPPEDWINDOW,	// window style
			     CW_USEDEFAULT,	// initial x position
			     CW_USEDEFAULT,	// initial y position
			     CW_USEDEFAULT,	// initial x size
			     CW_USEDEFAULT,	// initial y size
			     NULL,	// parent window handle
			     NULL,	// window menu handle
			     hInstance,	// program instance handle
			     NULL);	// creation parameters

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam,
			 LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	TCHAR szBuf[80];

	switch (message) {
	case WM_CREATE:
		PlaySound(TEXT("hellowin.wav"), NULL,
			  SND_FILENAME | SND_ASYNC);
		ShowWindow(hwnd, g_iCmdShow);
		UpdateWindow(hwnd);

		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rect);

		_sntprintf(szBuf, sizeof (szBuf) / sizeof (TCHAR), 
			TEXT ("%u Hello, Windows 98!"), hwnd);

		DrawText(hdc, szBuf, -1, &rect,
			 DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
