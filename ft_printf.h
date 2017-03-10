#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

#include <stdio.h>

# define STR "%5%"

typedef struct		s_prntf
{
	char			present;		// %
	char			*string;		// зберігає строку для s
	int				digit;			// зберигає цифрку ширини
	char			*flags;			// #0-+ and space
	char 			minus;
	char 			ziro;
	char 			hash;
	char 			plus;
	char			space;
	int 			number;         // зберігає цифру типа
	int				*length;		// hh, h, l, ll, j, et z
	int				*width;			// указывает минимальную ширину поля
	char			type;			// Спецификатор типа sSpdDioOuUxXcC
	ssize_t			str_len;		// длина string

}					t_prntf;

int					ft_printf(char *format, ...);

void	fill_digit(char *s, t_prntf **base);
void 	fill_flags(char *s, t_prntf **base);
void	fill_basetoziro(t_prntf *base);
void	fill_type(char *s, t_prntf **base);

int					chack_afte_pers(char c);
int 				isdigit_withoutziro(char c);
int		chack_type(char c);
int 	count_presents(char *s);


int main();

#endif
