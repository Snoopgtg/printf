#include "ft_printf.h"

int main()
{
	int m;
	int n;

	//-------------empty--------------------------------------
	/*m = ft_printf("%h05l%l ynu");
	printf("m = %d\n", m);
	ft_printf("\n");
	n = printf("%h05l%l ynu");
	printf("n = %d", n);
*/
	//-------------------%p-----------------------------------
	/*char c[] ="dfdf";
	char *k;
	char *p;

	k = c;
	p = k;
	m = ft_printf("[%-22.18p]", p);
	printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");
	n = printf("[%-22.18p]", p);
	printf("\nn = %d\n", n);*/

	//перевірити точність і довжину*******************************************

	//--------------%d----------------------------------------
	/*ft_printf("[% -+23.1d]", -45);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[% -+23.1d]", -45);
	printf("\nn = %d\n", n);*/


	//------------------%D--------------------------------
	/*ft_printf("[% -23.12D]", -45);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[% -23.12D]", -45);
	printf("\nn = %d\n", n);*/

	//------------------%o--------------------------------
	/*ft_printf("[%#+14.4o]", 45);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[%#+14.4o]", 45);
	printf("\nn = %d\n", n);*/

	//------------------%O--------------------------------
	/*ft_printf("[% -036O]", -9223372036854775807);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[% -036O]", -9223372036854775807);
	printf("\nn = %d\n", n);*/

	//------------------%u--------------------------------
	/*ft_printf("[%12.4hhu]", 255);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[%12.4hhu]", 255);
	printf("\nn = %d\n", n);*/

	//------------------%U--------------------------------
	/*ft_printf("[%9.4U]", 65536);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[%9.4U]", 65536);
	printf("\nn = %d\n", n);*/

	//-------------------%xX------------------------------------
	/*ft_printf("[%#5.1x]", 42);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[%#5.1x]", 42);
	printf("\nn = %d\n", n);*/

	//------------------%s--------------------------------
	/*m = ft_printf("[%012.2s]", "zap");
	printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[%012.2s]", "zap");
	printf("\nn = %d\n", n);*/

	//------------------%c--------------------------------
	/*ft_printf("[%.yod]", 0);
	//printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[% -12.yod]");
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
	/*m = ft_printf("[% 12 h . \nd yodav]", 10);
	printf("\nm = %d\n", m);
	printf("\n");
	printf("\n");

	n = printf("[% 12 h . \nd yodav]", 10);
	printf("\nn = %d\n", n);*/


	return 0;
}