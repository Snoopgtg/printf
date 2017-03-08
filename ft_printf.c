#include "ft_printf.h"
#include <stdio.h>

void	fill_digit(char *s, t_prntf **base)
{
	int 	i;
	char	*t;
	i = 0;
	t = s;
	while (*t)
	{
		(*t == '0') ? (*base)->ziro = '0' : 0;
		if (isdigit_withoutziro(*t))
		{
			(*base)->digit = ft_atoi(t) - 1;
			if ((i + (int)ft_lenitoa((*base)->digit) < (*base)->str_len))
			{
				i += (int)ft_lenitoa((*base)->digit);
				t += ft_lenitoa((*base)->digit);
			}
		}
		t++;
		i++;
	}

}

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
	(*base)->str_len = ft_strlen(s);
	while (*s && (chack_afte_pers(*s) || ft_isdigit(*s)))
	{
		(*s == ' ') ? (*base)->space = ' ' : 0;
		(*s == '+') ? (*base)->plus = '+' : 0;
		(*s == '-') ? (*base)->minus = '-' : 0;
		//(*s == '0') ? (*base)->ziro = '0' : 0;
		(*s == '#') ? (*base)->hash = '#' : 0;
		//(isdigit_withoutziro(*s)) ? (*base)->digit = ft_atoi(s) - 1 : 0;
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
			|| c == '+' || c == '-' || c == '#')
		return (1);
	return (0);
}

void	print_ziroorspase(char **format, t_prntf *base, int ***r)
{
	int f;

	f = 0;
	if ((chack_afte_pers(**format) || ft_isdigit(**format)) && **format)
	{
		if (base->minus == '-')
		{
			while ((chack_afte_pers(**format) || ft_isdigit(**format)) && **format)
				(*format)++;
			(**format) ? write(1, &(**format), 1) : 0 ;
			(**format) ? (*format)++ : 0 ;
			f = 0;
			(***r)++;
		}
		else
			(base->ziro == '0') ? f = 1 : 0;
		(***r) += base->digit;
		while (base->digit > 0)
		{
			(!f) ? write(1, " ", 1) : write(1, "0", 1);
			(base->digit)--;
		}
	}
}

void	chack_only_txt(char *format, t_prntf *base, int **r)
{
	while (*format)
	{
		if (*format == '%' && format++)
		{
			fill_flags(format, &base);
			fill_digit(format, &base);
			print_ziroorspase(&format, base, &r);
			while (chack_afte_pers(*format) || ft_isdigit(*format))
				format++;
			if (*format)
			{
				write(1, &(*format), 1);
				(**r)++;
			}
		}
		else
		{
			write(1, &(*format), 1);
			(**r)++;
		}
		(*format) ? format++ : 0 ;
	}
}

void	fill_formater(char *format, t_prntf *base, int *r)
{

	chack_only_txt(format, base, &r);

}


int		ft_printf(char *format, ...)
{
	int r;

	r = 0;
	t_prntf base[1];
	fill_basetoziro(base);
	fill_formater(format, base, &r);
	return (r);
}
int main()
{
	int k;

	k = ft_printf("%20.5%");
	ft_printf("\n");
	printf("%20.5%");
	printf("k = %d", k);
	//printf("[%ld]", (long)(-1));
	return 0;
}