# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 21:37:20 by ilevy             #+#    #+#              #
#    Updated: 2024/12/12 23:03:14 by ilevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name

NAME:= Fractol

# Compilator

CC:= cc
CFLAGS:= -Wall -Wextra -Werror -g

# Main Directories

LIBFT:= libft/# My precious Libft, i love you
SRC_DIR:= c_files/# Where i keep the cool stuff
H_FILES:= h_files/# Where the stuff is defined
OBJ_DIR:= o_files/# Where the junk .o goes
MLX:= mlx_linux/# Where the graphic stuff is

LIBFT_A:= libft.a# The archive of every c file i made thus far.
LIBMLX_A:= libmlx.a# To add to the comp
LIBLMX_LINUX_A:= libmlx_Linux.a# To add to the comp

# Source_files relative to themselves.

SRC_FILES:= ft_fractol.c ft_init.c ft_julia.c ft_mandelbrot.c \
			ft_error_handling.c ft_utils.c ft_hooks.c ft_burning.c

# Source_files and o_files relative to the makefile.

SRC:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ:= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# Include files.

LIB := $(addprefix $(LIBFT), $(LIBFT_A))
LIBMLX:= $(addprefix $(MLX), $(LIBMLX_A))
LIBMLX_LINUX:= $(addprefix $(MLX), $(LIBLMX_LINUX_A))
INCLUDE:= $(addprefix $(LIBFT), $(H_FILES))

# Commands to give

all:	$(NAME)

objdir_mk:
	@mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJ)
	@make -C $(LIBFT)
	@make all -C $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIBMLX) $(LIBMLX_LINUX) -lX11 -lm -lXext -o $@
	@echo "Compiled fractol!"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | objdir_mk
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@echo "Compiled the c files into o files!"

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@echo "Cleaned o_files, libft and mlx!"

fclean:	clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)
	@echo "Cleaned .a files and fractol!"

re:	fclean all

.PHONY: re all fclean clean objdir_mk
