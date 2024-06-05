NAME = get_next_line.a

SRCS = \
	get_next_line.c get_next_line_utils.c\
	get_next_line_bonus.c get_next_line_utils_bonus.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $(OBJS)

.PHONY: all clean re fclean bonus
re: fclean all

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -rf $(NAME)
