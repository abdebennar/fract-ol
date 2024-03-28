# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abennar <abennar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 15:22:22 by abennar           #+#    #+#              #
#    Updated: 2024/02/07 12:15:19 by abennar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c  ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_putchar.c ft_putstr.c \
	ft_putprsnt.c ft_putnbr.c ft_putusg.c ft_puthex.c ft_putptr.c \
	get_next_line.c get_next_line_utils.c ft_strcmp.c

MOBG = $(SOURCES:.c=.o)

CC = cc
FLAGC = -Wall -Wextra -Werror


all: $(NAME) 
	
$(NAME): $(MOBG)
	ar rc $@ $?

%.o: %.c libft.h
	$(CC) $(FLAGC) -o $@ -c $<

clean:
	rm -f $(MOBG)

fclean: clean
	rm -f $(NAME)

re: fclean all
