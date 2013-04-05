#include <conio.h>
#include <windows.h>

LONG lCounter;

BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	MessageBox(NULL, "First DLL", "DLL", MB_OK);
	return TRUE;
}

DWORD CheckCounter(void) {
	if (lCounter < 0) lCounter = 0;
	if (lCounter > 10) lCounter = 10;
	return lCounter;
}

DWORD IncCounter(void) {
	lCounter++;
	return CheckCounter();
}

DWORD DecCounter(void) {
	lCounter--;
	return CheckCounter();
}

DWORD ModC(DWORD dwNum1, DWORD dwNum2) {
	if (dwNum2) return dwNum1 % dwNum2;
	else return dwNum1;
}

int FAR PASCAL PortOut(short port, unsigned char value) {
	_outp(port, value); 
	return 1; 
}

int FAR PASCAL PortIn(short port) {
	int result;
	result=_inp(port);
	return (result);
}
