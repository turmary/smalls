#include <windows.h>
#include <windowsx.h>
#include <stdio.h>

class WLDialogBox {
public:
	virtual LRESULT WLDlgProc(HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		return DefDlgProcEx(hdlg, uMsg, wParam, lParam, &m_fRecursing);
	}

	INT_PTR DoModal(HINSTANCE hinst, LPCTSTR pszTemplate, HWND hwndParent) {
		return DialogBoxParam(hinst, pszTemplate, hwndParent, s_DlgProc, (LPARAM)this);
	}
private:
	static INT_PTR CALLBACK s_DlgProc(HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		printf("%s() msg = %d\n", __FUNCTION__, uMsg);

		if (uMsg == WM_INITDIALOG) {
			SetWindowLongPtr(hdlg, DWLP_USER, lParam);
			printf("INITDIALOG\n");
		}
		WLDialogBox *self = (WLDialogBox*)GetWindowLongPtr(hdlg, DWLP_USER);
		if (!self) {
			return FALSE;
		}
		CheckDefDlgRecursion(&self->m_fRecursing);
		return SetDlgMsgResult(hdlg, uMsg, self->WLDlgProc(hdlg, uMsg, wParam, lParam));
	}
	BOOL m_fRecursing;
};

class SampleWLDlg: public WLDialogBox {
	typedef WLDialogBox super;

	LRESULT WLDlgProc(HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		switch(uMsg) {
		HANDLE_MSG(hdlg, WM_COMMAND, OnCommand);
		HANDLE_MSG(hdlg, WM_SETCURSOR, OnSetCursor);
		}
		return super::WLDlgProc(hdlg, uMsg, wParam, lParam);
	}

	void OnCommand(HWND hdlg, int id, HWND hwndCtl, UINT codeNotify) {
		switch(id) {
		case IDCANCEL:
			MessageBox(hdlg, TEXT("Bye"), TEXT("Title"), MB_OK);
			EndDialog(hdlg, 1);
			break;
		}
	}

	BOOL OnSetCursor(HWND hdlg, HWND hwndCursor, UINT codeHitTest, UINT msg) {
		if (codeHitTest == HTCAPTION) {
			SetCursor(LoadCursor(NULL, IDC_SIZEALL));
			return TRUE;
		}
		SetCursor(LoadCursor(NULL, IDC_ARROW));
		return TRUE;
		//return FORWARD_WM_SETCURSOR(hdlg, hwndCursor, codeHitTest, msg, super::WLDlgProc);
	}
};

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev, LPSTR lpCmdLine, int nShowCmd) {
	SampleWLDlg dlg;

	dlg.DoModal(hinst, MAKEINTRESOURCE(1), NULL);
	return 0;
}
