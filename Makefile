# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nterrier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 18:49:12 by nterrier          #+#    #+#              #
#    Updated: 2017/02/01 21:53:54 by nterrier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c flags.c utils.c string.c number.c character.c nbr_base.c

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar rcs $(NAME) $(OBJ) libft/*.o
clean :
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean : clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re : fclean $(NAME)

maintest :
	gcc -c main.c
	gcc -o ft_printf libftprintf.a main.o
	rm main.o
