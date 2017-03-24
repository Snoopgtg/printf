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

	//-------------------%p-----------------------------------
	/*char c[] ="dfdf";
	char *k;
	char *p;

	k = c;
	p = k;
	m = ft_printf("[% 022p]", p);
	printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");
	n = printf("[% 022p]", p);
	printf("\nn = %d\n", n);*/

	//--------------%d----------------------------------------
	ft_printf("[% 021d]", 37);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[% 021d]", 37);
	printf("\nn = %d\n", n);

	//------------------%D--------------------------------
	/*ft_printf("[% -23D]", 9223372036854775807);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[% -23D]", 9223372036854775807);
	printf("\nn = %d\n", n);*/

	//------------------%o--------------------------------
	/*ft_printf("[% 010o]", 255);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[% 010o]", 255);
	printf("\nn = %d\n", n);*/

	//------------------%O--------------------------------
	/*ft_printf("% -036O|", -9223372036854775807);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("% -036O|", -9223372036854775807);
	printf("\nn = %d\n", n);*/

	//------------------%u--------------------------------
	/*ft_printf("[% -021u]", -129);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[% -021u]", -129);
	printf("\nn = %d\n", n);*/

	//------------------%U--------------------------------
	/*ft_printf("[%09U]", 65536);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[%09U]", 65536);
	printf("\nn = %d\n", n);*/

	//-------------------%xX------------------------------------
	/*ft_printf("% -09x]", 42949672);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("% -09x]", 42949672);
	printf("\nn = %d\n", n);*/

	//------------------%s--------------------------------
	/*ft_printf("% 012s", "asddd");
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("% 012s", "asddd");
	printf("\nn = %d\n", n);*/

	//------------------%c--------------------------------
	/*ft_printf("[%c]", 65);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[%c]", 65);
	printf("\nn = %d\n", n);*/

	//------------------%hd--------------------------------
	/*ft_printf("%hhhhd", 32767);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("%hhhhd", 32767);
	printf("\nn = %d\n", n);*/

	//------------------%ld--------------------------------
	/*ft_printf("%ld", 214748364789);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("%ld", 214748364789);
	printf("\nn = %d\n", n);*/

	//------------------%jd--------------------------------
	/*ft_printf("%ji", 214748364789);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("%ji", 214748364789);
	printf("\nn = %d\n", n);*/

	//------------------%jd--------------------------------
	/*ft_printf("%zd", 9223372036854775807);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("%zd", 9223372036854775807);
	printf("\nn = %d\n", n);*/




	//------------------%hhu--------------------------------
	/*ft_printf("%hhu", 257);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("%hhu", 257);
	printf("\nn = %d\n", n);*/

	//-----------------%hhX--------------------------------
	/*ft_printf("%h#X", 4294967299);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("%h#X", 4294967299);
	printf("\nn = %d\n", n);*/

	//------------------%hhx--------------------------------
	/*ft_printf("[%#-12x]", 256);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[%#-12x]", 256);
	printf("\nn = %d\n", n);*/


	//n = printf("%08d", -12);*********************************
	return 0;
}