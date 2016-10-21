#include <stdio.h>
#include <windows.h>

void NewLine(void);
void ScrollScreenBuffer(HANDLE, INT);

HANDLE hStdout, hStdin;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

void MyErrorExit(const char* err) {
	fprintf(stderr, err);
	exit(1);
}

void ScrollScreenBuffer(HANDLE hStdout, INT row) {
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	SMALL_RECT srctWindow;

	// Get the current screen buffer size and window position.
	if (! GetConsoleScreenBufferInfo(hStdout, &csbiInfo))
		MyErrorExit("GetConsoleScreenBufferInfo");

	// Set srctWindow to the current window size and location.
	srctWindow = csbiInfo.srWindow;

	// If window is not at the screen buffer top, move it up one line.
	if ( srctWindow.Top > 0 ) {
		srctWindow.Top -= 1;			// move top up by one row
		srctWindow.Bottom -= 1; 		// move bottom up by one row

		if (! SetConsoleWindowInfo(
					hStdout,	// screen buffer handle
					TRUE,		// absolute coordinates
					&srctWindow))	// specifies new location
			MyErrorExit("SetConsoleWindowInfo");
	}
	return;
}


int main(int argc, char* argv[]) {
	LPSTR lpszPrompt1 = "Type something and press Enter:\n";
	LPSTR lpszPrompt2 = "Type any key: ";
	CHAR chBuffer[256];
	DWORD cRead, cWritten, fdwMode, fdwOldMode;
	WORD wOldColorAttrs;

	// Get handles to STDIN and STDOUT.
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE || hStdout == INVALID_HANDLE_VALUE) {
		MyErrorExit("GetStdHandle");
	}

	// Save the current text colors.
	if (! GetConsoleScreenBufferInfo(hStdout, &csbiInfo))
		MyErrorExit("GetConsoleScreenBufferInfo");

	wOldColorAttrs = csbiInfo.wAttributes;

	// Set the text attr. to draw red text on black background.
	if (! SetConsoleTextAttribute(hStdout, FOREGROUND_RED))
		MyErrorExit("SetConsoleTextAttribute");

	// Write to STDOUT and read from STDIN by using the default
	// modes. Input is echoed automatically, and ReadFile
	// does not return until a carriage return is typed.
	//
	// The default input modes are line, processed, and echo.
	// The default output modes are processed and wrap at EOL.

	while (1)
	{
		if (! WriteFile(
		 hStdout,		// output handle
		 lpszPrompt1,		// prompt string
		 lstrlen(lpszPrompt1),	// string length
		 &cWritten,		// bytes written
		 NULL) )		// not overlapped
			break;
		if (! ReadFile(
		 hStdin,		// input handle
		 chBuffer,		// buffer to read into
		 255,			// size of buffer
		 &cRead,		// actual bytes read
		 NULL) )		// not overlapped
			break;
		if (chBuffer[0] == 'q') break;
	}

	// Turn off the line input mode, and echo the input mode.
	if (! GetConsoleMode(hStdin, &fdwOldMode))
		MyErrorExit("GetConsoleMode");

	fdwMode = fdwOldMode &
		~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	if (! SetConsoleMode(hStdin, fdwMode))
		MyErrorExit("SetConsoleMode");

	// Prompt for input.
	if (! WriteFile(
	 hStdout,			// output handle
	 lpszPrompt2,		 	// prompt string
	 lstrlen(lpszPrompt2),		// string length
	 &cWritten,			// bytes written
	 NULL) )			// not overlapped
		MyErrorExit("WriteFile");

	// Without line and echo input modes, ReadFile returns
	// when any input is available. Carriage returns must
	// be handled, and WriteFile is used to echo input.
	while (1) {
		if (! ReadFile(hStdin, chBuffer, 1, &cRead, NULL))
			break;
		if (chBuffer[0] == '\r')
			NewLine();
		else if (! WriteFile(hStdout, chBuffer, cRead,
			&cWritten, NULL)) break;
		if (chBuffer[0] == 'q') break;
	}

	// Restore the original console mode.
	if (! SetConsoleMode(hStdin, fdwOldMode))
		MyErrorExit("SetConsoleMode");

	// Restore the original text colors.
	if (! SetConsoleTextAttribute(hStdout, wOldColorAttrs))
		MyErrorExit("SetConsoleTextAttribute");
}

// The NewLine function handles carriage returns when the processed
// input mode is disabled. It gets the current cursor position
// and resets it to the first cell of the next row.

void NewLine(void)
{
	if (! GetConsoleScreenBufferInfo(hStdout, &csbiInfo))
		MyErrorExit("GetConsoleScreenBufferInfo");
	csbiInfo.dwCursorPosition.X = 0;

	// If it is the last line in the screen buffer, scroll
	// the buffer up.
	if ((csbiInfo.dwSize.Y-1) == csbiInfo.dwCursorPosition.Y) {
		ScrollScreenBuffer(hStdout, 1);
	} else {
		// Otherwise, advance the cursor to the next line.
		csbiInfo.dwCursorPosition.Y += 1;
	}

	if (! SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition)) {
		MyErrorExit("SetConsoleCursorPosition");
	}
}
