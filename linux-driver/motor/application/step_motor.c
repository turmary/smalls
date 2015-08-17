// tary, 18:13 2011-6-29
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define DEV_NAME "/dev/step_motor"

int main(int argc, char *argv[]) {
	int fd;
	int angle = 360;		//Ĭ����תһ��

	if (argc >= 2) {
		if (strncmp(argv[1], "-h", strlen("-h")) == 0) {
			printf("\nusage: \n\t%s [angle]", argv[0]);
			printf("\n\t  angle: angle motor will wheel");
			printf("\n");
			return 0;
		}
		angle = atoi(argv[1]);
	}

	fd = open(DEV_NAME, O_RDWR);
	if (fd == EOF) {
		printf("\nopen device %s error", DEV_NAME);
		printf("\n");
		return 1;
	}
	
	// д����ת�ĽǶ�
	printf("\nmotor wheel for %d degrees", angle);
	write(fd, &angle, sizeof angle);

	printf("\n");
	// ��ȡδת��ĽǶ�
	while (read(fd, &angle, sizeof angle)) {
		if (angle <= 0) {
			break;		//ֱ����ת����,�˳�
		}
		printf("\r\nnow %3d degrees leave", angle);
		usleep(100000);
	}

	printf("\n");
	close(fd);
	return 0;
}
