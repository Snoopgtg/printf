#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define STR "[%h   -2hh  2  h  z 0 yud-rt]\n"

typedef struct		s_prntf
{
	char			present;		// %
	char			*string;		// вся сторко форматора
	int				digit;			// зберигає цифрку
	char			*flags;			// #0-+ and space
	char 			minus;
	char 			ziro;
	char 			hash;
	char 			plus;
	char			space;
	int				*length;		// hh, h, l, ll, j, et z
	int				*width;			// указывает минимальную ширину поля
	char			*type;			// Спецификатор типа sSpdDioOuUxXcC
	ssize_t			str_len;		// длина string

}					t_prntf;

int					ft_printf(char *format, ...);

int					chack_afte_pers(char c);
int 				isdigit_withoutziro(char c);

#endif
