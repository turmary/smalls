/*-------------------------------------------------------------------
	SINEWAVE.C -- Sine Wave Using Polyline
		(c) Charles Petzold, 1998
---------------------------------------------------------------------*/

#include <windows.h>
#include <math.h>

#define NUM 50000
#ifndef M_PI
#define M_PI	3.14159
#endif
#ifndef _2_M_PI
#define _2_M_PI	(2 * M_PI)
#endif

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
			PSTR szCmdLine, int iCmdShow) {
	static TCHAR szAppName[] = TEXT("SineWave");
	HWND		hwnd;
	MSG		msg;
	WNDCLASS	wndclass;
	wndclass.style		= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.cbClsExtra	= 0;
	wndclass.cbWndExtra	= 0;
	wndclass.hInstance	= hInstance;
	wndclass.hIcon 		= LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor	= LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground	=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= szAppName;

	if (!RegisterClass(&wndclass)) {
		MessageBox(	NULL, TEXT("Program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow( szAppName, TEXT("Sine Wave Using Polyline"),
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT,
				CW_USEDEFAULT, CW_USEDEFAULT,
				NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

#if 0

/**********************************************************
               |-------|    /\  /\  /\  /\ L
              /|   R   |----  \/  \/  \/  \---\
             / |-------|                       \
-------------                                  /---------|
      |      \           | |                  /          |
      |       \----------| |-----------------/           |
      |                 C| |                             |
      |                                                  |
                                                         |
      V                                                  |
                                                         |
      |                                                  |
      |                                                  |
      |                    |---------|                   |
---------------------------|   R1    |------------------/
                           |---------|
**********************************************************/

int GeneratePoints(POINT* apt, int cnt, int maxx, int maxy) {
	int i;
	double R, L, C, R1;
	double I1, Ic, IL;
	double V1, Vc, VL;
	double dV, dI;
	double T, dt;
	double V;

	R = .5;			// Ohm
	L = 1.78E-9;		// Henry
	C = .67E-9;		// Farad
	R1 = 1.5;

	V = 0.0; 		// Vote
	I1 = Ic = IL = 0.0; 	// Amper
	V1 = Vc = VL = 0.0;	// Vote

	T = 2 * M_PI * sqrt(L * C);

	dt = 2.0L * T / cnt;

	// Capcitor	Ic = C * (dV / dt)
	// Inductor	Vl = L * (dI / dt)
	// Resistor	Vr = I * R

	for (i = 0; i < cnt; i++) {
		if (i <= cnt / 100) {
			V = 1.0 * i / (cnt / 100);
		}

		dV = 1.0L * Ic / C * dt;
		dI = 1.0L * VL / L * dt;

		Vc += dV;
		VL = Vc - IL * R;
		V1 = V - Vc;

		IL += dI;
		Ic = I1 - IL;
		I1 = V1 / R1;

		apt[i].x = i * maxx / cnt;
		apt[i].y = V1 * maxy;
	}
	
	return cnt;
}

#else

int GeneratePoints(POINT* apt, int cnt, int maxx, int maxy) {
	int i;
	double R, L, C, R1;
	double I1, Ic, IL;
	double V1, Vc, VL;
	double dV, dI;
	double T, dt;
	double V;

	R = 0.5;		// Ohm
	L = 1.78;		// Henry
	C = .67;		// Farad
	R1 = 0.0;

	V = 1.0; 		// Vote
	I1 = Ic = IL = 0.0; 	// Amper
	V1 = Vc = VL = 0.0;	// Vote

	Vc = V;

	T = 2.0 * M_PI * sqrt(L * C);

	dt = 5.0L * T / cnt;

	// Capcitor	Ic = C * (dV / dt)
	// Inductor	Vl = L * (dI / dt)
	// Resistor	Vr = I * R

	for (i = 0; i < cnt; i++) {
		dV = 1.0L * Ic / C * dt;
		dI = 1.0L * VL / L * dt;

		Vc += dV;
		VL = Vc - IL * R;
		V1 = V - Vc;

		IL += dI;
		Ic = I1 - IL;
		// I1 = V1 / R1;

		apt[i].x = i * maxx / cnt;
		apt[i].y = Vc * maxy;
	}
	
	return cnt;
}

#endif

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static int cxClient, cyClient;
	static POINT	apt[NUM];
	HDC		hdc;
	int		i;
	PAINTSTRUCT	ps;

	switch (message) {
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		MoveToEx(hdc, 0, cyClient / 2, NULL);
		LineTo	(hdc, cxClient, cyClient / 2);

#if 1
		for (i = 0; i < NUM; i++) {
			apt[i].x = i * cxClient / NUM;
			apt[i].y =(int)(cyClient / 2 *(1 - sin(_2_M_PI * i / NUM)));
		}
		
		Polyline(hdc, apt, NUM);
#else
		MoveToEx(hdc, 0, 20, NULL);
		LineTo	(hdc, cxClient, 20);
		GeneratePoints(apt, NUM, cxClient, cyClient / 2 - 20);

		for (i = 0; i < NUM; i++) {
			SetPixel(hdc, apt[i].x, cyClient / 2 - apt[i].y, RGB(255,0,0));
		}
#endif
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
