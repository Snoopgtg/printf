#include "ft_printf.h"

void	ft_putnbrui(unsigned int n)
{
	unsigned int res;

	res = n;
	if (res > 9)
	{
		ft_putnbr(res / 10);
	}
	ft_putchar(res % 10 + '0');
}