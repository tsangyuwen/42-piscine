#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytseng <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 13:09:51 by ytseng            #+#    #+#              #
#    Updated: 2019/04/17 22:40:44 by ytseng           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = src/ft_bsq.c src/ft_read.c src/main.c
NAME = bsq

all: compile_file

compile_file:
	gcc -Wall -Werror -Wextra -I includes/ -o $(NAME) $(SRCS)

.PHONY: fclean

fclean: 
	/bin/rm -f $(NAME)

re: fclean all
