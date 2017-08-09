#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <windows.h>
#include "resource\resource.h"

#define ID_TIMER	1
#define IDM_BACK1	100
#define IDM_BACK2	101
#define IDM_CIRCLE1	102
#define IDM_CIRCLE2	103
#define IDM_EXIT	104
#define CLOCK_SIZE	150
#define PI		3.1416

HINSTANCE hInstance;
HWND hWinMain, h2;
HCURSOR hCursorMove,	/*Cursor when move	*/
	hCursorMain;	/*Cursor when normal	*/
HMENU hMenu;

HBITMAP ghBmpBack, ghBmpClock;
HDC ghDcBack, ghDcClock;

DWORD dwNowBack, dwNowCircle;

char *szClassName = "Clock";
DWORD dwPara180 = 180,
dwRadius = CLOCK_SIZE/2;
char *szMenuBack1 =	"使用格子背景(&A)",
*szMenuBack2	=	"使用花布背景(&B)",
*szMenuCircle1	=	"使用淡蓝色边框(&C)",
*szMenuCircle2	=	"使用粉红色边框(&D)",
*szMenuExit	=	"退出(&X)...";


DWORD CalcX(DWORD dwDegree, DWORD dwR){
	return dwRadius + (int)(dwR * sin(dwDegree * PI / dwPara180));
}

DWORD CalcY(DWORD dwDegree, DWORD dwR){
	return dwRadius - (int)(dwR * cos(dwDegree * PI / dwPara180));
}

void DrawLine(HDC hDC, DWORD dwDegree, DWORD dwRadius) {
	DWORD dwX1, dwY1, dwX2, dwY2;

	dwX1 = CalcX(dwDegree, dwRadius);
	dwY1 = CalcY(dwDegree, dwRadius);
	dwDegree += 180;
	dwX2 = CalcX(dwDegree, 10);
	dwY2 = CalcY(dwDegree, 10);
	MoveToEx(hDC, dwX1, dwY1, NULL);
	LineTo(hDC, dwX2, dwY2);
	return;
}

void CreateClockPic(void) {
	DWORD Sec;
	HPEN hPen;
	SYSTEMTIME stTime;

	BitBlt(ghDcClock, 0, 0, CLOCK_SIZE, CLOCK_SIZE, ghDcBack, 0, 0, SRCCOPY);
	GetLocalTime(&stTime);
	SelectObject(ghDcClock, hPen = CreatePen(PS_SOLID, 1, RGB(0x6b, 0xc0, 0x37)));
	Sec = stTime.wSecond * 360 / 60;
	DrawLine(ghDcClock, Sec, 60);
	DeleteObject(hPen);

	SelectObject(ghDcClock, hPen = CreatePen(PS_SOLID, 2, RGB(0x38, 0x94, 0x55)));
	Sec = stTime.wMinute * 360 / 60;
	DrawLine(ghDcClock, Sec, 55);
	DeleteObject(hPen);

	SelectObject(ghDcClock, hPen = CreatePen(PS_SOLID, 3, RGB(0x52, 0xff, 0x77)));
	Sec = stTime.wHour;
	if (Sec >= 12) Sec -= 12;
	Sec *= 360 / 12;
	Sec += stTime.wMinute / 2;
	DrawLine(ghDcClock, Sec, 50);
	DeleteObject(hPen);

	hPen = (HPEN)GetStockObject(NULL_PEN);
	SelectObject(ghDcClock, hPen);
	DeleteObject(hPen);
	return;
}

void CreateBackGround(void) {
	HBRUSH hBr;
	HDC hDc, hDcCircle, hDcMask;
	HBITMAP hBmpBack, hBmpCircle, hBmpMask;

	hDc = GetDC(hWinMain);
	ghDcBack = CreateCompatibleDC(hDc);
	ghDcClock = CreateCompatibleDC(hDc);
	hDcMask = CreateCompatibleDC(hDc);
	hDcCircle = CreateCompatibleDC(hDc);
	ghBmpBack = CreateCompatibleBitmap(hDc, CLOCK_SIZE, CLOCK_SIZE);
	ghBmpClock = CreateCompatibleBitmap(hDc, CLOCK_SIZE, CLOCK_SIZE);
	ReleaseDC(hWinMain, hDc);

	hBmpBack = LoadBitmap(hInstance, (const char *)dwNowBack);
	hBmpCircle = LoadBitmap(hInstance, (const char *)dwNowCircle);
	hBmpMask = LoadBitmap(hInstance, (const char *)(dwNowCircle+1));
	SelectObject(ghDcBack, ghBmpBack);
	SelectObject(ghDcClock, ghBmpClock);
	SelectObject(hDcCircle, hBmpCircle);
	SelectObject(hDcMask, hBmpMask);

	hBr = CreatePatternBrush(hBmpBack);
	SelectObject(ghDcBack, hBr);
	PatBlt(ghDcBack, 0, 0, CLOCK_SIZE, CLOCK_SIZE, PATCOPY);
	DeleteObject(hBr);

	BitBlt (ghDcBack, 0, 0, CLOCK_SIZE, CLOCK_SIZE, hDcMask, 0, 0, SRCAND);
	BitBlt (ghDcBack, 0, 0, CLOCK_SIZE, CLOCK_SIZE, hDcCircle, 0, 0, SRCPAINT);
	DeleteDC (hDcCircle);
	DeleteDC (hDcMask);
	DeleteObject (hBmpBack);
	DeleteObject (hBmpCircle);
	DeleteObject (hBmpMask);
	return;
}

void DeleteBackGround(void) {
	DeleteDC (ghDcBack);
	DeleteDC (ghDcClock);
	DeleteObject (ghBmpBack);
	DeleteObject (ghBmpClock);
	return;
}

void Init(void) {
	HRGN TSt;
	HBITMAP hBmpBack, hBmpCircle;

	hMenu = CreatePopupMenu();
	AppendMenu (hMenu,0,IDM_BACK1, szMenuBack1);
	AppendMenu (hMenu,0,IDM_BACK2, szMenuBack2);
	AppendMenu (hMenu,MF_SEPARATOR,0,NULL);
	AppendMenu (hMenu,0,IDM_CIRCLE1, szMenuCircle1);
	AppendMenu (hMenu,0,IDM_CIRCLE2, szMenuCircle2);
	AppendMenu (hMenu,MF_SEPARATOR,0,NULL);
	AppendMenu (hMenu,0,IDM_EXIT, szMenuExit);
	CheckMenuRadioItem (hMenu,IDM_BACK1,IDM_BACK2,IDM_BACK1,0);
	CheckMenuRadioItem (hMenu,IDM_CIRCLE1,IDM_CIRCLE2,IDM_CIRCLE1,0);

	TSt = CreateEllipticRgn (0,0,CLOCK_SIZE+1,CLOCK_SIZE+1);
	SetWindowRgn (hWinMain, TSt, TRUE);
	DeleteObject (TSt);
	SetWindowPos (hWinMain, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	dwNowBack = IDB_BACK1;
	dwNowCircle = IDB_CIRCLE1;
	CreateBackGround();
	CreateClockPic();
	SetTimer (hWinMain, ID_TIMER, 1000, NULL);
	return;
}

void Quit(void) {
	KillTimer (hWinMain, ID_TIMER);
	DestroyWindow(hWinMain);
	PostQuitMessage(0);
	DeleteBackGround();
	DestroyMenu (hMenu);
	return;
}

/*LRESULT CALLBACK*/
long WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL InitWindowsClass(HINSTANCE);
BOOL InitWindows(HINSTANCE, int);
HWND hWndMain;

extern int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszCmdLIne,
	int nCmdShow) {
		MSG Msg;
		if (!InitWindowsClass(hInstance))
			return FALSE;
		if (!InitWindows(hInstance, nCmdShow))
			return FALSE;

		while(GetMessage(&Msg, NULL, 0, 0)) {
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		return Msg.wParam;
}

BOOL InitWindowsClass(HINSTANCE hInst){
	WNDCLASS wndclass;

	hInstance = hInst;
	hCursorMove = LoadCursor(hInstance, (const char*)IDC_MOVE);
	hCursorMain = LoadCursor(hInstance, (const char *)IDC_MAIN);

	//RtlZeroMemory (&wndclass, sizeof(wndclass));
	wndclass.hIcon = LoadIcon (hInstance, (const char *)ICO_MAIN);
	wndclass.hCursor = hCursorMain;
	wndclass.hInstance = hInst;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszClassName = szClassName;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	/*wndclass.lpszMenuName = NULL;
	*/
	return RegisterClass(&wndclass);
}

BOOL InitWindows(HINSTANCE hInst, int nCmdShow) {
	HWND hwnd;

	hwnd = CreateWindow (szClassName, 
		szClassName,
		WS_POPUP | WS_SYSMENU,
		CLOCK_SIZE,//CW_USEDEFAULT,
		2 * CLOCK_SIZE,//CW_USEDEFAULT,
		CLOCK_SIZE,
		CLOCK_SIZE,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (!hwnd) return FALSE;
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static UINT X = CLOCK_SIZE, Y = 2 * CLOCK_SIZE, unDir = 1;
	PAINTSTRUCT PtStr;
	HDC hDC;
	POINT stPos;
	static char lwP[20];
	
	switch(message) {
	case WM_TIMER:
		CreateClockPic ();
  		InvalidateRect (hwnd, 0, FALSE);
		//不要使用SendMessage (hwnd, WM_MOVE, 0, 20 * 1024 + 800);
		//使用如下代码
		if (unDir) X += 5;
		else	X-=5;
		if (X <= 0) unDir = 1;
		else if (X >= 1024-CLOCK_SIZE) unDir = 0;
		MoveWindow(hwnd, X, Y, CLOCK_SIZE, CLOCK_SIZE, TRUE);
		//UpdateWindow(hwnd);
		break;

	case WM_PAINT:
		hDC = BeginPaint (hwnd, &PtStr);
		BitBlt(hDC, PtStr.rcPaint.left, PtStr.rcPaint.top,
			PtStr.rcPaint.right - PtStr.rcPaint.left,
			PtStr.rcPaint.bottom - PtStr.rcPaint.top,
			ghDcClock, PtStr.rcPaint.left, PtStr.rcPaint.top, SRCCOPY);
		/*itoa(h2, lwP, 10);
		TextOut (hDC, 50, 20, lwP, strlen(lwP));
		itoa(hwnd, lwP, 10);
		TextOut (hDC, 50, 40, lwP, strlen(lwP));
		*/EndPaint(hwnd, &PtStr);
		break;

	case WM_CREATE:
		//assert(hWinMain != hwnd);
		//printf("%d %d\n", hWinMain, hwnd);
		hWinMain = hwnd;
		Init();
  		break;


	case WM_COMMAND:
		switch(LOWORD(wParam)){
		case IDM_BACK1:
			dwNowBack = IDB_BACK1;
			CheckMenuRadioItem (hMenu, IDM_BACK1, IDM_BACK2, IDM_BACK1, 0);
			break;

		case IDM_BACK2:
			dwNowBack = IDB_BACK2;
			CheckMenuRadioItem (hMenu, IDM_BACK1, IDM_BACK2, IDM_BACK2, 0);
			break;

		case IDM_CIRCLE1:
			dwNowCircle = IDB_CIRCLE1;
			CheckMenuRadioItem (hMenu, IDM_CIRCLE1, IDM_CIRCLE2, IDM_CIRCLE1, 0);
			break;

		case IDM_CIRCLE2:
			dwNowCircle = IDB_CIRCLE2;
			CheckMenuRadioItem (hMenu, IDM_CIRCLE1, IDM_CIRCLE2, IDM_CIRCLE2, 0);
			break;

		case IDM_EXIT:
			Quit();
			return 0;

		default:
			break;
		}
		DeleteBackGround();
		CreateBackGround();
		CreateClockPic();
		InvalidateRect (hwnd, NULL, FALSE);
		break;

	case WM_CLOSE:
		Quit();
		break;

	case WM_RBUTTONDOWN:
		GetCursorPos (&stPos);
		TrackPopupMenu (hMenu, TPM_LEFTALIGN, stPos.x, stPos.y, 0, hwnd, 0);
		break;

	case WM_LBUTTONDOWN:
		SetCursor (hCursorMove);
		UpdateWindow(hwnd);
		ReleaseCapture();
		SendMessage (hwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);
		SetCursor (hCursorMain);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

