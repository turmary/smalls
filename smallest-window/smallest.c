#include <windows.h>

//�Ի��򴰿ڴ�����
BOOL CALLBACK DlgProc(HWND hdlg, UINT message, WPARAM wParam, LPARAM lParam){
	switch (message) {
	case WM_INITDIALOG:
		return 1;
	//������Ϣ����Ϣ
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
	//MessageBox(NULL, "��򴰿���\nһ���Ի���", "Hello!", MB_OK);

	while (GetMessage(&Msg, NULL, 0, 0)) {
		//�ػ��ģ̬�Ի�����Ϣ������������
		if (!IsDialogMessage(hdlg, &Msg)) {
			DispatchMessage(&Msg);
		}
	}
	return Msg.wParam;
}
