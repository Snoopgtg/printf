/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgogol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:59:34 by tgogol            #+#    #+#             */
/*   Updated: 2017/04/11 15:01:00 by tgogol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** fhesh для корректного виводу вісмковій системі коли є #
** 		 та для корректного виводу вказівника;
** fchar для корректного виводу чарів;
** fstr = 1 для корректного виводу строкі;
** fstr = 10 для d, i, u;
** fstr = 16 для x, X;
** fstr = 8  для o, O;
*/

void	print_width(t_prntf *bs, int fhesh, int fchar)
{
	int c;
	int f;

	f = 1;
	c = (int)ft_strlen(bs->str);
	if (c <= bs->nw)
	{
		c = bs->nw - c - fhesh + fchar;
		while (c-- > 0)
		{
			if (bs->spc && f && (bs->tp == 'd' || bs->tp == 'D' ||
				bs->tp == 'i'))
				f = 0;
			else
			{
				if (bs->z)
					print_aka_flags(1, '0', bs);
				else
					print_aka_flags(1, ' ', bs);
			}
		}
	}
}

void	print_s(t_prntf *bs)
{
	int p;
	int l;
	int k;

	if ((char *)(bs->nbr) == NULL)
		bs->str = "(null)";
	else
		bs->str = ((char *)(bs->nbr));
	if (bs->prc != -1)
	{
		k = (int)ft_strlen(bs->str);
		p = (k > bs->prc) ? bs->prc : k;
		l = (bs->nw - p);
		(!bs->m && bs->z) ? print_aka_flags(l, '0', bs) : 0;
		(!bs->m && !bs->z) ? print_aka_flags(l, ' ', bs) : 0;
		write(1, (bs->str), p);
		bs->r += p;
		(bs->m && bs->z) ? print_aka_flags(l, '0', bs) : 0;
		(bs->m && !bs->z) ? print_aka_flags(l, ' ', bs) : 0;
	}
	(bs->nw != 0 && !bs->m && bs->prc == -1) ? print_width(
			bs, 0, 0) : 0;
	if (bs->prc == -1)
		print_aka_flags(1, 'p', bs);
	(bs->m && bs->prc == -1) ? print_width(bs, 0, 0) : 0;
}

void	print_c(t_prntf *bs)
{
	(bs->nw != 0 && !bs->m) ? print_width(bs, 1, 0) : 0;
	{
		write(1, &(bs->nbr), 1);
		bs->r++;
	}
	(bs->m) ? print_width(bs, 1, 0) : 0;
}

void	print(t_prntf *bs)
{
	if (ft_strchr("dDioscuUoOxXpbnC", bs->tp))
	{
		(bs->tp == 'd' || bs->tp == 'i' || bs->tp == 'D') ? print_di(bs) : 0;
		(bs->tp == 's') ? print_s(bs) : 0;
		(bs->tp == 'c' || bs->tp == 'C') ? print_c(bs) : 0;
		(bs->tp == 'u' || bs->tp == 'U') ? print_u(bs) : 0;
		(bs->tp == 'X' || bs->tp == 'x') ? print_x(bs) : 0;
		(bs->tp == 'o' || bs->tp == 'O') ? print_o(bs) : 0;
		(bs->tp == 'p') ? print_p(bs) : 0;
		(bs->tp == 'b') ? print_b(bs) : 0;
		(bs->tp == 'n') ? do_n(bs) : 0;
	}
	else
		print_c(bs);
}

void	print_symbol(char **format, t_prntf *bs)
{
	while (**format != '%' && **format)
	{
		write(1, *format, 1);
		bs->r++;
		(*format)++;
	}
}
