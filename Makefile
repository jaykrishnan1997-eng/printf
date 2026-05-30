# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/07 12:41:02 by jkrishna          #+#    #+#              #
#    Updated: 2026/05/30 14:37:50 by jkrishna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = 	ft_printf.c \
		ft_channel.c \
		ft_cprintf.c \
		ft_sprintf.c \
		ft_pprintf.c \
		ft_uprintf.c \
		ft_diprintf.c \
		ft_xprintf.c \
		ft_cxprintf.c \
		ft_percprintf.c \
		ft_wrap.c

OBJ = $(SRC:.c=.o)

AR = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

#bonus: all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o	

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

