#include "../../include/head.h"
#include <time.h>
#include <sys/time.h> // gettimeofday

int timetest()
{
    time_t t;
	struct tm *ptm;
	struct timeval tv;
	t = time(NULL);
	ptm = localtime(&t);
	gettimeofday(&tv, NULL);

	printf("year = %d\nmonth = %d\nday = %d\n", ptm->tm_year + 1900,
			ptm->tm_mon + 1, ptm->tm_mday);
	printf("%02d%02d%02d\n", ptm->tm_year + 1900,
			ptm->tm_mon + 1, ptm->tm_mday);
	printf("%04d:%04d:%04d\n", ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	printf("seconds = %d\n", (int)tv.tv_sec);
	printf("microseconds = %d\n", (int)tv.tv_usec);
	printf("ctime = %s\n", ctime(&t));

	return 0;
}
