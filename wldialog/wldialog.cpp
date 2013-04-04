#include <windows.h>
#include <windowsx.h>
#include <stdio.h>

typedef LRESULT (CALLBACK*  WLDLGPROC)(HWND, UINT, WPARAM, LPARAM);

struct WLDIALOGINFO {
	WLDLGPROC wldp;
	LPARAM lParam;
};

INT_PTR CALLBACK WLDlgProc(HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam) {
	printf("\t\t%s() msg = %d\n", __FUNCTION__, uiMsg);
	return FALSE;
}

LRESULT CALLBACK SampleWLDialogProc (
	HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam
) {
	printf("\t%s() msg = %d\n", __FUNCTION__, uiMsg);

	switch(uiMsg) {
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		switch(GET_WM_COMMAND_ID(wParam, lParam)) {
		case IDCANCEL:
			MessageBox(hdlg, TEXT("Bye"), TEXT("Title"), MB_OK);
			EndDialog(hdlg, 1);
			break;
		}
		break;
	case WM_SETCURSOR:
		if (LOWORD(lParam) == HTCAPTION) {
			SetCursor(LoadCursor(NULL, IDC_SIZEALL));
			return TRUE;
		}
		break;
	}

	return DefDlgProc(hdlg, uiMsg, wParam, lParam);
}

LRESULT CALLBACK WLWndProc(HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam) {
	printf("%s() msg = %d\n", __FUNCTION__, uiMsg);

	if (uiMsg == WM_INITDIALOG) {
		WLDIALOGINFO * pwldi = (WLDIALOGINFO*)lParam;
		SetWindowLongPtr(hdlg, DLGWINDOWEXTRA, (LONG_PTR)pwldi->wldp);
		lParam = pwldi->lParam;
		printf("INITDIALOG\n");
	}
	WLDLGPROC wldp = (WLDLGPROC)GetWindowLongPtr(hdlg, DLGWINDOWEXTRA);

	if (wldp) {
		return wldp(hdlg, uiMsg, wParam, lParam);
	} else {
		return DefDlgProc(hdlg, uiMsg, wParam, lParam);
	}
}

INT_PTR WLDialogBoxParam(
	HINSTANCE hinst, LPCTSTR pszTemplate, HWND hwndParent, WLDLGPROC wldp, LPARAM lParam
) {
	WLDIALOGINFO wldi = {wldp, lParam };
	return DialogBoxParam(hinst, pszTemplate, hwndParent, WLDlgProc, (LPARAM)&wldi);
}

HINSTANCE g_hinst;

BOOL InitApp(void) {
	WNDCLASS wc;

	wc.style	= CS_DBLCLKS | CS_SAVEBITS | CS_BYTEALIGNWINDOW;
	wc.lpfnWndProc	= WLWndProc;
	wc.cbClsExtra	= 0;
	wc.cbWndExtra	= DLGWINDOWEXTRA + sizeof(WLDLGPROC);
	wc.hInstance	= g_hinst;
	wc.hIcon 	= NULL;
	wc.hCursor	= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground= NULL;
	wc.lpszMenuName	= NULL;
	wc.lpszClassName= TEXT("WLDialog");

	return RegisterClass(&wc);
}

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev, LPSTR lpCmdLine, int nShowCmd) {
	g_hinst = hinst;

	InitApp();
	WLDialogBoxParam(hinst, MAKEINTRESOURCE(1), NULL, SampleWLDialogProc, 0);
}
