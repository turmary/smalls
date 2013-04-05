#include <stdio.h>
#include <string.h>

#define D_S_MAIN 1
#define D_S 1

#if D_S
void clrscr(void);
#endif

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31}
};

int day_of_year (int year, int month, int day) {
	int i, leap;

	if (year < 0 || 1 > month || month > 12)
		return -1;
	if (1 > day || day > daytab[month])
		return -1;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

int month_day (int year, int yearday, int* pmonth, int* pday) {
	int i, leap;

	if (!pmonth || pday == NULL)
		return -1;
	if (year < 0 || 1 > yearday || yearday > 366)
		return -1;
        leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
	return 0;
}

#if D_S_MAIN
int main() {
	int y, m, d, dy = 138;

#if D_S
	clrscr();
#endif

	y = 1986;
	m = 5;
	d = 4;
	printf("The day of %04d-%02d-%02d\n is the %dth day of the year.\n",
	  y, m, d, day_of_year(y, m, d));
	if (month_day(y, dy, &m, &d) == -1) return 1;
	printf("The %dth day of the year %d is %04d-%02d-%02d.\n",
	 dy, y, y, m, d);
	return 0;
}
#endif

