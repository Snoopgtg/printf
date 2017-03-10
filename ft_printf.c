#include "ft_printf.h"

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

int 	count_presents(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%')
				s++;
			i++;
		}
		s++;
	}
	return (i);
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

void	print(t_prntf *base, int *r)
{
	(base->type == 'd') ? ft_putnbr(base->number) : 0 ;
	(base->type == 'i') ? ft_putnbr(base->number) : 0 ;
}

void	fill_formater(char *format, t_prntf *base, int *r)
{
	//chack_d(format, base, &r);
	chack_only_txt(format, base, &r);

}

void	chack_valist(char *s, va_list ap, t_prntf **base)
{
	while (*s && (chack_afte_pers(*s) || ft_isdigit(*s)))
		s++;
	((*base)->type == 'd') ? (*base)->number = va_arg(ap, int) : 0 ;
	((*base)->type == 'i') ? (*base)->number = va_arg(ap, int) : 0 ;
}

void	new_main(char *format, t_prntf *base, va_list ap)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			fill_flags(format, &base);
			fill_digit(format, &base);
			fill_type(format, &base);
			chack_valist(format, ap, &base);
		}
		format++;
	}
}


int		ft_printf(char *format, ...)
{
	int 	r;
	va_list ap;
	t_prntf base[1];

	r = 0;
	va_start(ap, format);
	fill_basetoziro(base);
	new_main(format, base, ap);
	print(base, &r);
	//fill_formater(format, base, &r);
	return (r);
}