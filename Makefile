NAME	= push_swap
CC		= gcc
FLAGS	= -Wall -Wextra -Werror 

SRC	 =			check_error.c \
				global_sorting.c \
				help_for_sorting_one.c \
				help_for_sorting_two.c \
				main.c \
				rule.c \
				split.c \
				utils_for_main.c \
				utils_for_stack.c \
				utils_liba.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

norm:
	norminette -R CheckDefine

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re norm

