# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#              #
#    Updated: 2023/01/25 14:40:37 by asarikha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME = fractol

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Minilibx
MLX_PATH	= mlx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)
MLX_LNK	= -L ./mlx -l mlx -framework OpenGL -framework AppKit 

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./includes/\
				-I ./libft/\
				-I ./mlx/
				
# Sources				
SRC_PATH	=	src/
SRC			=	fractol.c help_message.c initializing.c terminate.c utils.c render.c mandelbrot.c \
				julia.c event.c
SRCS		= $(addprefix $(SRC_PATH),$(SRC))

# Objects
OBJ			= $(SRC:.c=.o)

.PHONY: all clean fclean re
all: $(MLX) $(LIBFT) $(NAME)

%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(INC) -Imlx -c $< -o $@

$(MLX):
	@echo "Making MiniLibX..."
	make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	@echo "Compiling fractol..."
	$(CC) $(CFLAGS) $(MLX) $(MLX_LNK) $(LIBFT) -o $(NAME) $(OBJ) $(INC)
	@echo "Fractol ready."

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all	