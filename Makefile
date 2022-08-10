CFLAGS = -Wall -Werror -Wextra -g

NAME = pipex

LIBFT_DIR = ./libft
LIBFT_EXEC = ./libft/libft.a
LIBFT_HEAD = ./libft/

SRCS = pipex.c utils.c extract_path.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_EXEC)
		gcc $(CFLAGS) $(OBJS) $(LIBFT_EXEC) -o $(NAME)
		@echo "Ready to use!"

$(LIBFT_EXEC):
		@echo "Compiling libft"
		cd $(LIBFT_DIR) && make

clean:
	rm -rf $(OBJS)
	cd $(LIBFT_DIR) && make clean

fclean:
	rm -rf $(OBJS) ./$(NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean all
.PHONY: all clean fclean re
