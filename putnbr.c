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

void	ft_putnbrl(long n)
{
	if (n < 0)
	{
		n *= (-1);
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbrl(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

void	ft_putnbrll(long long n)
{
	if (n < 0)
	{
		n *= (-1);
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbrll(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

void	ft_putnbrst(size_t n)
{
	if (n > 9)
	{
		ft_putnbrst(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

void	ft_putnbrimt(intmax_t n)
{
	if (n < 0)
	{
		n *= (-1);
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbrimt(n / 10);
	}
	ft_putchar(n % 10 + '0');
}