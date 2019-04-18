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

all: compile_file

compile_file:
	gcc -Wall -Wextra -Werror -I includes/ -o bsq src/*.c

.PHONY: clean

clean:
	rm bsq

re: clean all