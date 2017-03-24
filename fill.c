#include "ft_printf.h"

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
			(*base)->digit = ft_atoi(t);
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

void 	fill_flags(char *s, t_prntf **base)
{
	(*base)->str_len = ft_strlen(s);
	while (*s && (chack_afte_pers(*s) || ft_isdigit(*s)))
	{
		(*s == ' ') ? (*base)->space = ' ' : 0;
		(*s == '+') ? (*base)->plus = '+' : 0;
		(*s == '-') ? (*base)->minus = '-' : 0;
		(*s == '#') ? (*base)->hash = '#' : 0;
		s++;
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
	base->number = 0;
	base->type = 0;
	base->length = 0;
	base->r = 0;
	base->str = ft_strnew(0);
}

int		chack_type(char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
		|| c== 'U' || c == 'X' || c == 'x' || c == 'c' || c == 'D' || c == 'O')
		return (1);
	return (0);
}

void	fill_type(char *s, t_prntf **base)
{

	while (*s && (chack_afte_pers(*s) || ft_isdigit(*s)))
		s++;
	if (chack_type(*s))
		(*base)->type = *s;
}

int		chack_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		chack_flags(char c)
{
	if (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		chack_minus_in_type(char c)
{
	if (c == '-')
		return 1;
	return (0);
}

void	fill_length(char *s, t_prntf **base)
{
	while ((*s) && (chack_flags(*s) || ft_isdigit(*s) || *s == '.' || chack_length(*s)
			|| chack_length(*s)))
	{
		if (*s == 'h')
		{
			if ((*base)->length == 'h')
				(*base)->length = 'H';
			else if ((*base)->length != 'l' && (*base)->length != 'L' && (*base)->length != 'z'
					&& (*base)->length != 'j')
				(*base)->length = 'h';
		}
		if (*s == 'l')
		{
			if ((*base)->length == 'l')
				(*base)->length = 'L';
			else if ((*base)->length != 'z' || (*base)->length != 'j')
				(*base)->length = 'l';
		}
		if (*s == 'z')
			(*base)->length = ((*base)->length != 'j') ? 'z' : 'j';
		(*s == 'j') ? (*base)->length = 'j': 0;
		s++;

	}
}

void	fill_priority(char *s, t_prntf **base)
{
	if ((*base)->ziro == '0' && (chack_flags((*base)->length) ||
			(*base)->minus == '-'))
		(*base)->ziro = 0;
	if ((*base)->space == ' ' && (*base)->plus == '+')
		(*base)->space = 0;
}

void	fill_base(char *format, t_prntf *base)
{
	fill_flags(format, &base);
	fill_digit(format, &base);
	fill_type(format, &base);
	fill_length(format, &base);
	fill_priority(format, &base);
}
