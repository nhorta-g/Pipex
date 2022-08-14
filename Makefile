CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

NAME = pipex
NAME_B = pipex_b

LIBFT_DIR = ./libft/
LIBFT_EXEC = ./libft/libft.a

SRCS = pipex.c utils.c path_and_execute.c
SRCS_DIR = ./srcs/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(SRCS_PATH:.c=.o)

SRCS_B =  pipex_bonus.c utils_bonus.c get_next_line.c path_and_execute_bonus.c
SRCS_B_DIR = ./srcs_b/
SRCS_B_PATH = $(addprefix $(SRCS_B_DIR), $(SRCS_B))
OBJS_B = $(SRCS_B_PATH:.c=.o)

BIN_DIR = ./bin/
BIN_DIR_B = ./bin_b/

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_EXEC)
		clang $(CFLAGS) $(OBJS) $(LIBFT_EXEC) -o $(addprefix $(BIN_DIR), $(NAME))
		@echo "$(GREEN)Mandatory $(NAME) created. Ready to use!$(DEFAULT)"

$(LIBFT_EXEC):
		@echo "$(BLUE)Compiling libft$(DEFAULT)"
		cd $(LIBFT_DIR) && make

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B) $(LIBFT_EXEC)
		clang $(CFLAGS) $(OBJS_B) $(LIBFT_EXEC) -o $(addprefix $(BIN_DIR_B), $(NAME_B))
		@echo "$(GREEN)Bonus $(NAME_B) created. Ready to use!$(DEFAULT)"

$(LIBFT_EXEC):
		@echo "$(BLUE)Compiling libft$(DEFAULT)"
		cd $(LIBFT_DIR) && make

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)
	cd $(LIBFT_DIR) && make clean
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:
	rm -rf $(OBJS) $(addprefix $(BIN_DIR), $(NAME))
	rm -rf $(OBJS_B) $(addprefix $(BIN_DIR_B), $(NAME_B))
	cd $(LIBFT_DIR) && make fclean
	@echo "$(RED)all deleted!$(DEFAULT)"

re: fclean all
re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
GREEN_FULL = \033[7;32m
DEFAULT = \033[0m
