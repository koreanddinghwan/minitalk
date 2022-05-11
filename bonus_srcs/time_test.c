#include <time.h>
#include <stdio.h>

void	print_time()
{
	time_t	now;

	time(&now);
	printf("time : %s\n", ctime(&now));
}
