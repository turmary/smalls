#include <stdio.h>
#include <string.h>

#define D_S_MAIN 1
#define D_S 1

#if D_S
void clrscr(void);
#endif

#define	MAXLINES	500
/*char* lineptr[MAXLINES];*/

#define MAXLEN 100
int readlines(char lineptr[][MAXLEN], int nlines);
void writelines(char lineptr[][MAXLEN], int nlines);

void qsort(char lineptr[][MAXLEN], int left, int right);

#if D_S_MAIN
int main() {
	char lineptr[MAXLINES][MAXLEN];
	int nlines;

#if D_S
	clrscr();
#endif
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
	return 0;
}
#endif

int getline(char *, int);
char* malloc(int);

int readlines(char lineptr[][MAXLEN], int maxlines) {
	int len, nlines;
	char line[MAXLEN];

	nlines = 0;
	while((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(lineptr[nlines++], line);
		}
	return nlines;
}

void writelines(char lineptr[][MAXLEN], int nlines) {
	int i;

	for (i = 0; i < nlines; ++i)
		printf("%s\n", lineptr[i]);
}

/*read a line and return the length of it*/
int getline(char* s, int len) {
	int c, i;

	for(i = 0; i < len-2 && (c = fgetc(stdin)) != EOF && c != '\n'; ++i)
		*s++ = c;
	if(c == '\n') {
		*s++ = c;
		i++;
	}
	*s = '\0';
	return i;
}

void qsort(char v[][MAXLEN], int left, int right) {
	int i, last;
	void swap(char v[][MAXLEN], int i, int j);

	if (left >= right) return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char v[][MAXLEN], int i, int j) {
	char temp[MAXLEN];

	strcpy(temp, v[i]);
	strcpy(v[i], v[j]);
	strcpy(v[j], temp);
}
