#include <windows.h>

LRESULT CALLBACK WP(HWND h, UINT m, WPARAM w, LPARAM l) {
	if (m == WM_DESTROY) PostQuitMessage(0);
	return DefWindowProc(h, m, w, l);
}

int PASCAL WinMain(HINSTANCE h, HINSTANCE hP, LPSTR CL, int CS) {
	HWND hwnd;MSG Msg;WNDCLASS w;
	w.hIcon = (HICON)(w.cbWndExtra = w.cbClsExtra = w.style = 0);
	w.lpfnWndProc = WP;
	w.hInstance = h;
	w.hbrBackground = GetStockObject(WHITE_BRUSH);
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.lpszClassName = "S";
	RegisterClass(&w);
	hwnd = CreateWindowEx(0, "S", "SMALL WINDOW", WS_SYSMENU,
	 20, 20, 800, 600,
	 NULL, NULL, h, NULL);
	ShowWindow(hwnd, CS);
	while(GetMessage(&Msg, NULL, 0, 0)) DispatchMessage(&Msg);
	return Msg.wParam;
}
