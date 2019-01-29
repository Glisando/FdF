# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 14:51:54 by hdanylev          #+#    #+#              #
#    Updated: 2017/11/07 17:18:32 by hdanylev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE = *.c
HEADER = libft.h
TOU = *.o
CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -c $(SOURCE) -I $(HEADER) 
	ar rc $(NAME) $(TOU)

clean:
	rm -f $(TOU)

fclean: clean
	rm -f $(NAME)

re: fclean all
