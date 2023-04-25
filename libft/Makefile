NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

INCDIR	=	../include
INC		=	$(INCDIR)/libft.h

SRCS	=	ft_atoi.c \
			ft_isdigit.c \
			ft_memcpy.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_realloc.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strjoin.c \
			ft_strlcpy.c \
			ft_strlen.c \
			get_next_line.c

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all