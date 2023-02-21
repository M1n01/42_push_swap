NAME = libft.a

CC = cc
INCDIR = ../include
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

SRCDIR = ./

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