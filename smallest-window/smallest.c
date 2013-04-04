#include <windows.h>

//对话框窗口处理函数
BOOL CALLBACK DlgProc(HWND hdlg, UINT message, WPARAM wParam, LPARAM lParam){
	switch (message) {
	case WM_INITDIALOG:
		return 1;
	//处理消息框消息
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			DestroyWindow(hdlg);
			exit(1);
			return 1;
		}
		break;

	case WM_CLOSE:
		DestroyWindow(hdlg);
		exit(1);
		return 1;
	}
	return 0;
}


int PASCAL WinMain(HINSTANCE h, HINSTANCE hP, LPSTR CL, int CS) {
	MSG Msg;
	HWND hdlg = CreateDialog(h, "About", NULL, (DLGPROC) DlgProc);
	//MessageBox(NULL, "最简窗口是\n一个对话框", "Hello!", MB_OK);

	while (GetMessage(&Msg, NULL, 0, 0)) {
		//截获非模态对话框消息并发往处理函数
		if (!IsDialogMessage(hdlg, &Msg)) {
			DispatchMessage(&Msg);
		}
	}
	return Msg.wParam;
}
