#include <stdio.h>
#include <locale.h>

int main()
{
    wchar_t s[] = L"你好";
    setlocale(LC_ALL, "");
    wprintf(L"%s\n", s);
    return 0;
}
