#include <stdio.h>
#include "fcntl.h"
#include "windows.h"

int main(int argc, const char* argv[]) {
	if (TRUE) {
		DWORD consoleModeIn;
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

		GetConsoleMode(hStdin, &consoleModeIn);
		consoleModeIn = consoleModeIn & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
		SetConsoleMode(hStdin, consoleModeIn);
	} else {
		setvbuf(stdin, NULL, _IONBF, 0);
		setbuf(stdin, NULL);
	}

	_setmode(_fileno(stdin), _O_BINARY);

	putchar(getchar());

	fprintf(stderr, "hello world!\n");
	return 0;
}
