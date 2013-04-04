/****************************************************************************
    PURPOSE: Demonstrates create a window using class BUTTON which Windows defined 
****************************************************************************/
#include "windows.h"

WNDPROC DefButtonProc = DefWindowProc;

long FAR PASCAL WndProc(HWND hWnd, UINT message, WORD wParam, LONG lParam) {
	if (WM_LBUTTONUP == message) {
		PostQuitMessage(0);return -1;
	}
	return ((*DefButtonProc) (hWnd, message, wParam, lParam));
}

int PASCAL WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	HWND hWnd, hSub;

	hWnd = CreateWindowEx(0, "BUTTON",
			    "Normal Button",
			    0,
			    CW_USEDEFAULT, CW_USEDEFAULT, 240, 240,
			    NULL, NULL, hInst, NULL);
	if (!hWnd)	return (FALSE);

	hSub = CreateWindowEx(0, "BUTTON",
	  "Sub Button",
	  WS_CHILD | WS_VISIBLE,
	  CW_USEDEFAULT, CW_USEDEFAULT, 120, 120,
	  hWnd, NULL, hInst, NULL);

	DefButtonProc = (WNDPROC) SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProc);
	DefButtonProc = (WNDPROC) SetWindowLong(hSub, GWL_WNDPROC, (LONG) WndProc);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0)) DispatchMessage(&msg);
	return (msg.wParam);
}

