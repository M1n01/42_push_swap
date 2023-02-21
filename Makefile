NAME = push_swap

CC = cc
INCDIR = ./include
SRCDIR = ./srcs
UTILDIR = ./utils
LIBDIR = ./utils

CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

INC = $(shell find $(INCDIR) -name "*.h" -type f | xargs)
SRCS = $(shell find $(SRCDIR) -name "*.c" -type f | xargs)
UTILS = $(shell find $(UTILDIR) -name "*.c" -type f | xargs)
LIBFT = $(shell find $(LIBDIR) -name "*.c" -type f | xargs)

LIB = ./libft/libft.a

OBJS = $(SRCS:%.c=%.o)
UTILS_OBJ = $(UTILS:%.c=%.o)

$(NAME): $(OBJS) $(UTILS_OBJ)
		$(MAKE) -C ./libft
		$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(B_OBJS) $(UTILS_OBJ) $(LIBFT)

fclean: clean
		$(RM) $(NAME) $(LIB)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

norm:
		@norminette -R CheckDefine $(INC)
		@norminette -R CheckForbiddenSourceHeader $(SRCS) $(B_SRCS) $(UTILS)

.PHONY: all clean fclean re bonus norm debug
