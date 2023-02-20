NAME = libftprintf.a

CC = cc
INCDIR = ./ft_printf  ./libft
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

SRCDIR = ./ft_printf ./libft

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