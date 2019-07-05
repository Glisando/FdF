# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 19:40:39 by hdanylev          #+#    #+#              #
#    Updated: 2018/03/28 15:41:06 by hdanylev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


       # name of the executable file

NAME =		fdf

	# project directories

SRC_DIR =	./src/
OBJ_DIR =	./obj/
INC_DIR =	./inc/
LIB_DIR =	./libft/

	# project source files

SRC = main.c draw_util.c key_hook.c util.c util2.c draw.c calculate_coords.c

	# project object files

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

	# libraries

LIBFT =		$(LIBFT_DIR)libftprintf.a
LIBFT_DIR =	$(LIB_DIR)
LIBFT_INC = $(LIBFT_DIR)
LIBFT_FLAGS = -lft -L $(LIBFT_DIR)

	# compilation flags

CC_FLAGS	=	-Wall -Wextra -Werror

	# linking flags

LINK_FLAGS =   $(LIBFT_FLAGS)

	# header flags

HEADER_FLAGS = -I $(INC_DIR)  -I $(LIBFT_INC)

	# compiler

CC =			gcc

	# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(OBJ) ./libft/libft.a -o $(NAME) -lmlx -framework OpenGL -framework AppKit

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(INC_DIR)
		$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
		rm -f $(OBJ)
		make clean -C $(LIBFT_DIR)
fclean: clean
		rm -f $(NAME)
		rm -rf $(OBJ_DIR)
		make fclean -C $(LIBFT_DIR)
re: fclean all

vpath %.c $(SRC_DIR)
