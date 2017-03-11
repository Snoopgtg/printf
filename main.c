#include "ft_printf.h"

int main()
{
	int m;
	int n;


	//-------------empty--------------------------------------
	/*m = ft_printf("%h5l%l ynu", 42);
	printf("m = %d\n", m);
	ft_printf("\n");
	n = printf("%h5l%l ynu", 42);
	printf("n = %d", n);*/

	//--------------%d----------------------------------------
	ft_printf("my = %+d", 123);
	//printf("\nm = %d\n", m);
	printf("\n");

	n = printf("no = %+d", 123);
	printf("\nn = %d", n);
	//printf("[%ld]", (long)(-1));
	return 0;
}