#include <stdio.h>
#include <time.h>
#include <conio.h>

int main(){
	time_t Today;
        time_t biggest = 0x7FFFFFFF;
	char* TodayString;
	double second, minute, hour, day, week, month, year;

	/*clrscr();
	*/Today = time(NULL);
	TodayString = asctime(gmtime(&Today));
	printf("Current Time of Local: %s\n", TodayString);
	printf("biggest = %s \n", asctime(gmtime(&biggest)));
	printf("The difference between them (s): %10.0lf\n",
	 (second = difftime(biggest, Today)));
	week = (day = (hour = (minute = second / 60) / 60) / 24) / 7;
	month = day / 31;
	year = day / 365;
	printf("Convert :\n\tyear:\t %10.0lf\n\tmonth:\t %10.0lf\n\tweek:\t %10.0lf\n\t"
	 "day:\t %10.0lf\n\thour:\t %10.0lf\n\tminute:\t %10.0lf\n", year, month, week,
	 day, hour, minute);
	return 0;
}
