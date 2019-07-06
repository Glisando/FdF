# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 17:07:17 by hdanylev          #+#    #+#              #
#    Updated: 2018/06/20 22:19:07 by hdanylev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

    # name of the executable file

NAME = fdf

	# project directories

SRC_DIR =	./src/
OBJ_DIR =	./obj/
INC_DIR =	./inc/
LIB_DIR =	./libft/
	# project source files

SRC =	 main.c draw_util.c key_hook.c util.c util3.c util2.c draw.c calculate_coords.c wu_algo.c

	# project object files

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT =		$(LIBFT_DIR)libft.a
LIBFT_DIR =	$(LIB_DIR)
LIBFT_INC = $(LIBFT_DIR)
LIBFT_FLAGS = -lft -L $(LIBFT_DIR)

	# project header files

HDRS = inc/fdf.h

	# compilation flags

GCC_FLAGS	=	-Wall -Wextra -Werror 
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
	# header flags

HEADER_FLAGS = -I $(INC_DIR)

	# compiler

GCC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(GCC) $(GCC_FLAGS)$(MLX_FLAGS) $(LIBFT) $(OBJ) -o $(NAME)
	@echo "\033[31mFdF \033[35mMAKED\033[0m"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HDRS)
		$(GCC) $(GCC_FLAGS) $(HEADER_FLAGS) -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "\033[35mCLEANED\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[35mCLEANED ALL\033[0m"

re: fclean all 

vpath %.c $(SRC_DIR)
.PHONY: all clean fclean re
