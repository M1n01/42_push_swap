NAME = libftprintf.a

CC = cc
INCDIR = -I./include
SRCDIR = .
CFLAGS = -Wall -Wextra -Werror $(INCDIR)

SRCS = $(shell find $(SRCDIR) -name "*.c" -type f | xargs)

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
