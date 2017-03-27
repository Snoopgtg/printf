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

size_t	len_oct_hex(intmax_t n, int base)
{
	size_t i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

void	print_width(t_prntf *base)
{
	size_t l;
	size_t w;

	l = ft_strlen(base->str);
	w = ft_strlen(base->str);
	w = (w >= base->width) ? 0 : base->width - w;
	l = (l >= base->digit) ? 0 : base->digit - w - (ft_strlen(base->str));
	if (base->minus != '-')
	{
		while (l-- > 0)
			write(1, " ", 1);
		while (w-- > 0)
			write(1, "0", 1);
		ft_putstr(base->str);
	}
	if (base->minus == '-')
	{
		while (w-- > 0)
			write(1, "0", 1);
		ft_putstr(base->str);
		while (l-- > 0)
			write(1, " ", 1);
	}
}

void	print_width_m(t_prntf *base)
{
	size_t l;
	size_t w;

	l = ft_strlen(base->str);
	w = ft_strlen(base->str);
	w = (w >= base->width) ? 0 : base->width - w;
	l = (l >= base->digit) ? 0 : base->digit - w - (ft_strlen(base->str));
	if (base->minus != '-')
	{
		l--;
		while (l-- > 0)
			write(1, " ", 1);
		write(1, "-", 1);
		w++;
		while (w-- > 0)
			write(1, "0", 1);
		ft_putstr(base->str + 1);
	}
	if (base->minus == '-')
	{
		write(1, "-", 1);
		w++;
		while (w-- > 0)
			write(1, "0", 1);
		ft_putstr(base->str + 1);
		l--;
		while (l-- > 0)
			write(1, " ", 1);
	}
}

void 	print_length(t_prntf *base, int fhesh, int fchar, int fstr)
{

/*
 ** fhesh для корректного виводу вісмковій системі коли є #
 ** 		 та для корректного виводу вказівника;
 ** fchar для корректного виводу чарів;
 ** fstr = 1 для корректного виводу строкі;
 ** fstr = 10 для d, i, u;
 ** fstr = 16 для x, X;
 ** fstr = 8  для o, O;
 */

	size_t c;
	int f;

	f = 1;
	c = (fstr == 1) ? ft_strlen((char *)base->number) : ft_strlen(base->str);
	if (c <= base->digit)
	{
		c = base->digit - c - fhesh + fchar;
		while (c-- > 0)
		{
			if (base->space == ' ' && f && (base->type == 'd' || base->type == 'D' || base->type == 'i'))
				f = 0;
			else
				(base->ziro == '0') ? write(1, "0", 1) : write(1, " ", 1);
		}
	}
}

void	print_p(t_prntf *base)
{
	char *s;

	(base->ziro == '0' && base->minus != '-') ? write(1, "0x", 2) : 0;
	(base->digit != 0 && base->minus == 0) ? print_length(base, 2, 0, 16) : 0;
	(base->ziro != '0') ? write(1, "0x", 2) : 0;
	s = ft_itoa_base_pf((unsigned long int)(base->number), 16, 'x');
	ft_putstr(s);
	base->r = (base->digit > 14) ? base->digit + 2 : (int)ft_strlen(s) + 2;
	(base->minus == '-') ? print_length(base, 2, 0, 16) : 0;
}

void 	print_di_m(t_prntf *base)
{
	base->ziro == '0' ? write(1, "-", 1) : 0;
	(base->digit != 0 && base->minus == 0) ? print_length(base, 0, 0, 10) : 0;
	(base->minus == '-') ? ft_putstr((base)->str) : 0;
	(base->minus == '-') ? print_length(base, 0, 0, 10) : 0;
	(base->minus != '-') ? ft_putstr(base->str + 1) : 0;
}

void	print_di(t_prntf *base)
{
	(base->length == 0) ? base->str = ft_itoa_base((int)(base->number), 10) : 0;
	(base->length == 'H') ? base->str = ft_itoa_base((signed char)(base->number), 10) : 0;
	(base->length == 'h') ? base->str = ft_itoa_base((short)(base->number), 10) : 0;
	(base->length == 'l') ? base->str = ft_itoa_base((long)(base->number), 10) : 0;
	(base->length == 'L') ? base->str = ft_itoa_base((long long)(base->number), 10) : 0;
	(base->length == 'j' || base->length =='z') ? base->str = ft_itoa_base((intmax_t)(base->number), 10) : 0;
	if (base->width != -1 && !(base->f_width) && !chack_minus_in_type(*(base->str)))
		print_width(base);
	if (base->width != -1 && !(base->f_width) && chack_minus_in_type(*(base->str)))
		print_width_m(base);
	else if (chack_minus_in_type(*(base->str)) && base->width == -1)
		print_di_m(base);
	else if (base->width == -1 || (base->f_width))
	{
		(base->space == ' ') ? write(1, " ", 1) : 0;
		(base->ziro == '0' && base->plus == '+') ? write(1, "+", 1) : 0;
		if (base->digit != 0 && base->minus == 0)
			(base->plus == '+') ? print_length(base, 1, 0, 10) : print_length(base, 0, 0, 10);
		(base->ziro == 0 && base->plus == '+') ? write(1, "+", 1) : 0;
		((base->plus == '+' && base->minus == '-') || base->minus == '-') ? ft_putstr(base->str) : 0;
		if (base->minus == '-')
			(base->plus == '+') ? print_length(base, 1, 0, 10) : print_length(base, 0, 0, 10);
		((base->plus == '+' && base->minus != '-') || base->minus != '-') ? ft_putstr(base->str) : 0;
	}
}

void	print_upper_d(t_prntf *base)
{
	if (base->length == 0 || base->length == 'h' || base->length == 'H' || base->length == 'l')
		base->str = ft_itoa_base((long)(base->number), 10);
	(base->length == 'L') ? base->str = ft_itoa_base((long long)(base->number), 10) : 0;
	(base->length == 'j' || base->length =='z') ? base->str = ft_itoa_base((intmax_t)(base->number), 10) : 0;
	if (chack_minus_in_type(*(base->str)))
		print_di_m(base);
	else
	{
		(base->space == ' ') ? write(1, " ", 1) : 0;
		(base->ziro == '0' && base->plus == '+') ? write(1, "+", 1) : 0;
		if (base->digit != 0 && base->minus == 0)
			(base->plus == '+') ? print_length(base, 1, 0, 10) : print_length(base, 0, 0, 10);
		(base->ziro == 0 && base->plus == '+') ? write(1, "+", 1) : 0;
		((base->plus == '+' && base->minus == '-') || base->minus == '-') ? ft_putstr(base->str) : 0;
		if (base->minus == '-')
			(base->plus == '+') ? print_length(base, 1, 0, 10) : print_length(base, 0, 0, 10);
		((base->plus == '+' && base->minus != '-') || base->minus != '-') ? ft_putstr(base->str) : 0;
	}
}

void	print_o(t_prntf *base)
{
	(base->length == 0) ? base->str = ft_itoa_base_pf((unsigned int)(base->number), 8, 'x') : 0;
	(base->length == 'H') ? base->str = ft_itoa_base_pf((unsigned char)(base->number), 8, 'x') : 0;
	(base->length == 'h') ? base->str = ft_itoa_base_pf((unsigned short )(base->number), 8, 'x') : 0;
	(base->length == 'l') ? base->str = ft_itoa_base_pf((unsigned long )(base->number), 8, 'x') : 0;
	(base->length == 'L') ? base->str = ft_itoa_base_pf((unsigned long long)(base->number), 8, 'x') : 0;
	(base->length == 'j') ? base->str = ft_itoa_base_pf((uintmax_t)(base->number), 8, 'x') : 0;
	(base->length == 'z') ? base->str = ft_itoa_base_pf((size_t)(base->number), 8, 'x') : 0;

	if (base->digit != 0 && base->minus == 0)
		(base->hash == '#') ? print_length(base, 1, 0, 8) : print_length(base, 0, 0, 8);
	(base->hash == '#') ? write(1, "0", 1) : 0;
	ft_putstr(base->str);
	if (base->minus == '-')
		(base->hash == '#') ? print_length(base, 1, 0, 8) : print_length(base, 0, 0, 8);
}

void	print_upper_o(t_prntf *base)
{
	if (base->digit != 0 && base->minus == 0)
		(base->hash == '#') ? print_length(base, 1, 0, 8) : print_length(base, 0, 0, 8);
	(base->hash == '#') ? write(1, "0", 1) : 0;
	if (base->length == 0 || base->length == 'h' || base->length == 'H' || base->length == 'l')
		ft_putstr(ft_itoa_base_pf((long unsigned)(base->number), 8, 'x'));
	(base->length == 'L') ? ft_putstr(ft_itoa_base_pf((long long unsigned)(base->number), 8, 'x')) : 0;
	(base->length == 'j') ? ft_putstr(ft_itoa_base_pf((uintmax_t)(base->number), 8, 'x')) : 0;
	(base->length == 'z') ? ft_putstr(ft_itoa_base_pf((size_t)(base->number), 8, 'x')) : 0;
	if (base->minus == '-')
		(base->hash == '#') ? print_length(base, 1, 0, 8) : print_length(base, 0, 0, 8);
}

void	print_u(t_prntf *base)
{
	(base->digit != 0 && base->minus == 0) ? print_length(base, 0, 0, 10) : 0;
	(base->length == 0) ? ft_putnbrui((unsigned int)(base->number)) : 0;
	(base->length == 'H') ? ft_putnbr((unsigned char)(base->number)) : 0;
	(base->length == 'h') ? ft_putnbr((unsigned short)(base->number)) : 0;
	(base->length == 'l') ? ft_putnbrl((unsigned long)(base->number)) : 0;
	(base->length == 'L') ? ft_putnbrll((unsigned long long)(base->number)) : 0;
	(base->length == 'j') ? ft_putnbrimt((uintmax_t)(base->number)) : 0;
	(base->length == 'z') ? ft_putnbrst((size_t)(base->number)) : 0;
	(base->minus == '-') ? print_length(base, 0, 0, 10) : 0;

}

void	print_upper_u(t_prntf *base)
{
	(base->digit != 0 && base->minus == 0) ? print_length(base, 0, 0, 10) : 0;
	if (base->length == 0 || base->length == 'h' || base->length == 'H' || base->length == 'l')
		ft_putnbrl((unsigned long)(base->number));
	(base->length == 'L') ? ft_putnbrll((unsigned long long)(base->number)) : 0;
	(base->length == 'j') ? ft_putnbrimt((uintmax_t)(base->number)) : 0;
	(base->length == 'z') ? ft_putnbrst((size_t)(base->number)) : 0;
	(base->minus == '-') ? print_length(base, 0, 0, 10) : 0;
}

void	print_x(t_prntf *base, char c)
{
	(base->digit != 0 && base->hash != '#' && base->minus == 0) ? print_length(base, 0, 0, 16) : 0;
	if (base->hash == '#')
	{
		write(1, "0", 1);
		ft_putchar(c);
	}
	(base->length == 0) ? ft_putstr(ft_itoa_base_pf((unsigned int)(base->number), 16, c)) : 0;
	(base->length == 'H') ? ft_putstr(ft_itoa_base_pf((unsigned char)(base->number), 16, c)) : 0;
	(base->length == 'h') ? ft_putstr(ft_itoa_base_pf((unsigned short )(base->number), 16, c)) : 0;
	(base->length == 'l') ? ft_putstr(ft_itoa_base_pf((unsigned long )(base->number), 16, c)) : 0;
	(base->length == 'L') ? ft_putstr(ft_itoa_base_pf((unsigned long long)(base->number), 16, c)) : 0;
	(base->length == 'j') ? ft_putstr(ft_itoa_base_pf((uintmax_t)(base->number), 16, c)) : 0;
	(base->length == 'z') ? ft_putstr(ft_itoa_base_pf((size_t)(base->number), 16, c)) : 0;
	if (base->minus == '-')
		(base->hash == '#') ? print_length(base, 2, 0, 16) : print_length(base, 0, 0, 16);
}

void	print_s(t_prntf *base)
{
	(base->digit != 0 && base->minus == 0) ? print_length(base, 0, 0, 1) : 0;
	ft_putstr((char *)(base->number));
}

void	print_c(t_prntf *base)
{
	(base->digit != 0 && base->minus == 0) ? print_length(base, 0, 1, 10) : 0;
	ft_putchar((char)(base->number));
	(base->minus == '-') ? print_length(base, 0, 1, 10) : 0;
}

void	print(t_prntf *base)
{
	(base->type == 'd' || base->type == 'i') ? print_di(base) : 0;
	(base->type == 'D') ? print_upper_d(base) : 0;
	(base->type == 's') ? print_s(base) : 0;
	(base->type == 'c') ? print_c(base) : 0;
	(base->type == 'u') ? print_u(base) : 0;
	(base->type == 'U') ? print_upper_u(base) : 0;
	(base->type == 'X') ? print_x(base, base->type): 0;
	(base->type == 'x') ? print_x(base, base->type): 0;
	(base->type == 'o') ? print_o(base) : 0 ;
	(base->type == 'O') ? print_upper_o(base) : 0;
	(base->type == 'p') ? print_p(base) : 0 ;

}

void	fill_formater(char *format, t_prntf *base, int *r)
{
	//chack_d(format, base, &r);
	chack_only_txt(format, base, &r);

}
void	print_symbol(char **format)
{
	while (**format != '%' && **format)
	{
		write(1, *format, 1);
		(*format)++;
	}
}

void	skip_flags_length_type(char **s)
{
	while(**s &&(chack_flags(**s) || chack_length(**s) || chack_type(**s)
		|| ft_isdigit(**s)))
		(*s)++;
}

void	chack_valist(char *s, va_list ap, t_prntf *base)
{
	while (*s && (chack_afte_pers(*s) || ft_isdigit(*s)))
		s++;
	((base)->type == 'd') ? (base)->number = va_arg(ap, void *) : 0 ;
	((base)->type == 'i') ? (base)->number = va_arg(ap, void *) : 0 ;
	((base)->type == 's') ? base->number = va_arg(ap, void *) : 0 ;
	((base)->type == 'c') ? (base)->number = va_arg(ap, void *) : 0 ;
	((base)->type == 'u') ? (base)->number = va_arg(ap, void *) : 0 ;
	((base)->type == 'U') ? (base)->number = va_arg(ap, void *) : 0 ;
	((base)->type == 'X') ? (base)->number = va_arg(ap, void *) : 0 ;
	((base)->type == 'x') ? (base)->number = va_arg(ap, void *) : 0 ;
	((base)->type == 'o') ? (base)->number = va_arg(ap, void *) : 0 ;
	((base)->type == 'p') ? (base)->number = va_arg(ap, void *) : 0 ;
	((base)->type == 'D') ? (base)->number = va_arg(ap, void *) : 0 ;
	(base->type == 'O') ? (base)->number = va_arg(ap, void *) : 0 ;

}

void	new_main(char *format, t_prntf *base, va_list ap)
{
	while (*format)
	{
		print_symbol(&format);
		if (*format == '%')
		{
			format++;
			fill_base(format, base);
			chack_valist(format, ap, base);
			skip_flags_length_type(&format);
			//chack_flags(format, base);
			print(base);
		}
		(*format) ? write(1, &(*format), 1) : 0;
		(*format) ? format++ : 0;
	}
}


int		ft_printf(char *format, ...)
{
	va_list ap;
	t_prntf base[1];

	va_start(ap, format);
	fill_basetoziro(base);
	new_main(format, base, ap);
	va_end(ap);
	return (base->r);
}