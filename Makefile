#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 15:39:03 by ysavenko          #+#    #+#              #
#    Updated: 2017/02/27 16:27:06 by ysavenko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

OBJ =   ft_printf.o		\
		ft_isdigit.o	\
		ft_strlen.o 	\
		ft_itoa_base.o	\
		ft_putstr.o		\
		ft_strchr.o		\
		ft_putchar.o 	\
		ft_strcmp.o 	\
		fill.o 			\
		ft_strdel.o 	\
		check.o 		\
		fill_n_is.o 	\
		print_char.o	\
		print_prec_flags.o 	\
		print_type_uoxbn.o 	\
		print_cast_pdi.o 	\
		ft_strnew.o 		\
		wchar.o


all: $(NAME)

$(NAME) : $(OBJ)
	ar -cru $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: ./%.c ft_printf.h
	gcc -Wall -Wextra -Werror -o $@ -c  $< 

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all