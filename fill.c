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
}

int		chack_type(char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
		|| c == 'x' || c == 'c')
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