#include "ft_printf.h"
#include <stdio.h>

void	fill_basetoziro(t_prntf *base)
{
	base->digit = 0;
	base->minus = 0;
	base->plus = 0;
	base->ziro = 0;
	base->hash = 0;
	base->space = 0;
}

void 	fill_flags(char *s, t_prntf **base)
{
	while (*s && (chack_afte_pers(*s) || ft_isdigit(*s)))
	{
		(*s == ' ') ? (*base)->space = ' ' : 0;
		(*s == '+') ? (*base)->plus = '+' : 0;
		(*s == '-') ? (*base)->minus = '-' : 0;
		(*s == '0') ? (*base)->ziro = '0' : 0;
		(*s == '#') ? (*base)->hash = '#' : 0;
		(isdigit_withoutziro(*s)) ? (*base)->digit = ft_atoi(s) - 1 : 0;
		s++;
	}
}

int 	isdigit_withoutziro(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

int		chack_afte_pers(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == ' ' || c == '.'
			|| c == '+' || c == '-' || c == '#' /*|| (c >= '0' && c <= '9')*/)
		return (1);
	return (0);
}

void	print_ziroorspase(char **format, t_prntf *base)
{
	int f;

	f = 0;
	if ((chack_afte_pers(**format) || (ft_isdigit(**format) && **format)))
	{
		if (base->minus == '-')
		{
			while ((chack_afte_pers(**format) || (ft_isdigit(**format) && **format)))
				(*format)++;
			(**format) ? write(1, &(**format), 1) : 0 ;
			(**format) ? (*format)++ : 0 ;
			f = 1;
		}
		while (base->digit > 0)
		{
			(!f) ? write(1, "0", 1) : write(1, " ", 1);
			(base->digit)--;
		}
	}
}

void	chack_only_txt(char *format, t_prntf *base)
{
	while (*format)
	{
		if (*format == '%' && format++)
		{
			fill_flags(format, &base);
			print_ziroorspase(&format, base);
			while (chack_afte_pers(*format) || ft_isdigit(*format))
				format++;
			write(1, &(*format), 1);
		}
		else
			write(1, &(*format), 1);
		format++;
	}

}

void	fill_formater(char *format, t_prntf *base)
{

	chack_only_txt(format, base);

}


int		ft_printf(char *format, ...)
{
	t_prntf base[1];
	fill_basetoziro(base);
	fill_formater(format, base);
	return (0);
}
int main()
{
	ft_printf("my ="STR, 1);
	ft_printf("no ="STR, 1);
	//printf("[%ld]", (long)(-1));
	return 0;
}