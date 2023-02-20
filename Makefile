NAME = push_swap

CC = cc
INCDIR = ./include
SRCDIR = ./srcs

CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

INC = $(shell find $(INCDIR) -name "*.h" -type f | xargs)
SRCS = $(shell find $(SRCDIR) -name "*.c" -type f | xargs)
UTILS = $(shell find ./utils -name "*.c" -type f | xargs)
LIB = ./utils/libftprintf.a

OBJS = $(SRCS:%.c=%.o)
UTILS_OBJ = $(UTILS:%.c=%.o)

$(NAME): $(OBJS)
		$(MAKE) -C ./utils
		$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(B_OBJS) $(UTILS_OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

norm:
		@norminette -R CheckDefine $(INC)
		@norminette -R CheckForbiddenSourceHeader $(SRCS) $(B_SRCS) $(UTILS)

.PHONY: all clean fclean re bonus norm debug
