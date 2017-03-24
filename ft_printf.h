#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

#include <stdio.h>

typedef struct		s_prntf
{
	char			present;		// %
	char			*str;		// зберігає строку для s
	int 			ch;				// зберігає чар с
	unsigned int	nfu;			// зберігає число для u
	int				digit;			// зберигає цифрку ширини
	char			*flags;			// #0-+ and space
	char 			minus;
	char 			ziro;
	char 			hash;
	char 			plus;
	char			space;
	int				r;				// повернення надрукованих символів
	void 			*number;        // зберігає цифру типа
	char			length;			// j, z, ll, l, h, hh
	int				width;			// указывает минимальную ширину поля
	char			type;			// Спецификатор типа sSpdDioOuUxXcC
	ssize_t			str_len;		// длина string

}					t_prntf;

int					ft_printf(char *format, ...);

void	fill_base(char *format, t_prntf *base);
void	fill_digit(char *s, t_prntf **base);
void 	fill_flags(char *s, t_prntf **base);
void	fill_basetoziro(t_prntf *base);
void	fill_type(char *s, t_prntf **base);

void	ft_putnbrui(unsigned int n);
void	ft_putnbrl(long n);
void	ft_putnbrll(long long n);
void	ft_putnbrimt(intmax_t n);
void	ft_putnbrst(size_t n);
void	ft_putnbr_for_u(int n);

int					chack_afte_pers(char c);
int 				isdigit_withoutziro(char c);
int		chack_type(char c);
int		chack_flags(char c);
int		chack_length(char c);
int 	count_presents(char *s);
int		chack_minus_in_type(char c);

void	skip_flags_length_type(char **s);
char	*ft_itoa_base_pf(long unsigned int value, int base, char c);
char	*ft_itoa_base(intmax_t value, int base);


int main();

#endif
