# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abennar <abennar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 12:18:20 by abennar           #+#    #+#              #
#    Updated: 2024/02/14 21:19:42 by abennar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= chck_args.c fract_init.c main.c \
			math.c ship_set.c events.c  utils.c \
			julia_set.c mandelbrot.c render.c
NAME		=fractol
NAME_B		=fractol_bonus
LIBFT		=./libft/libft.a
CFLAGS		=-Wall -Wextra -Werror
MLX_FLAGS	=-lmlx -framework OpenGL -framework AppKit
ACT_BONUS	=-D BONUS=true

all : libft $(NAME)

# ------------------------------------------------------- #

libft :
	$(MAKE) -C ./libft

# ------------------------------------------------------- #

$(NAME) : $(SRC) fract_ol.h
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT) $(SRC) -o $@

clean :
	$(MAKE) clean -C ./libft

fclean : 
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
	rm -f $(NAME_B)

re :
	$(MAKE) fclean 
	$(MAKE) all

# ------------------------------------------------------- #

bonus : libft $(NAME_B) 

$(NAME_B) : $(SRC) fract_ol.h
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT) $(ACT_BONUS) $(SRC) -o $@

# ------------------------------------------------------- #


.PHONY : libft 