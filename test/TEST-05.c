#include <io.h>
#include <stdio.h>

int main() {
	int fd = 1;
	char buffer[100] = {0};
	const char* cs = "write to fd 1\n";

	sprintf(buffer, "write to fd 2\n");
	write(2, buffer, strlen(buffer));

	write(fd, cs, strlen(cs));

	return 0;
}
