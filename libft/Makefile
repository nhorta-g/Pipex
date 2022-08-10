# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nunograzina <nunograzina@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 11:06:33 by nhorta-g          #+#    #+#              #
#    Updated: 2022/07/28 12:14:23 by nunograzina      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha \
	  ft_isdigit \
	  ft_isalnum \
	  ft_isascii \
	  ft_isprint \
	  ft_strlen \
	  ft_memset \
	  ft_bzero \
	  ft_memcpy \
	  ft_memmove \
	  ft_strlcpy \
	  ft_strlcat \
	  ft_toupper \
	  ft_tolower \
	  ft_strchr \
	  ft_strrchr \
	  ft_strncmp \
	  ft_memchr \
	  ft_memcmp \
	  ft_strnstr \
	  ft_atoi \
	  ft_calloc \
	  ft_strdup \
	  ft_substr \
	  ft_strjoin \
	  ft_strtrim \
	  ft_split \
	  ft_itoa \
	  ft_strmapi \
	  ft_striteri \
	  ft_putchar_fd \
	  ft_putstr_fd \
	  ft_putendl_fd \
	  ft_putnbr_fd \

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)

clean:
	$(RM)	$(SRC:=.o)

fclean: clean
		$(RM)	$(NAME)

re:	fclean	$(NAME)
.PHONY: all clean fclean re
