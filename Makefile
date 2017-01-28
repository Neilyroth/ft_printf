# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nterrier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 18:49:12 by nterrier          #+#    #+#              #
#    Updated: 2017/01/28 17:01:34 by nterrier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

FUNCT = main.c ft_printf.c flags.c utils.c     string.c number.c pointer.c character.c nbr_base.c

OBJ = $(FUNCT:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME): $(OBJ)
#	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -I libft/ -o $(NAME) $(OBJ) -L libft/ -lft

clean :
#	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean : clean
#	@make -C libft/ fclean
	@rm -rf $(NAME)

re : fclean $(NAME)
