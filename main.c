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
	m = ft_printf("%i", -37);
	printf("m = %d\n", m);
	ft_printf("\n");
	n = printf("%c", 'c');
	printf("n = %d", n);
	//printf("[%ld]", (long)(-1));
	return 0;
}