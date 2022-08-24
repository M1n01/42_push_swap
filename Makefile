NAME = push_swap

CC = cc
INCDIR = ./include ./utils/include
SRCDIR = ./srcs
BONUS = ./bonus

CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

INC = $(shell find $(INCDIR) -name "*.h" -type f | xargs)
SRCS = $(shell find $(SRCDIR) -name "*.c" -type f | xargs)
B_SRCS = $(shell find $(BONUSDIR) -name "*.c" -type f | xargs)
UTILS = $(shell find ./utils -name "*.c" -type f | xargs)

OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)

ifdef WITH_BONUS
	OBJS += $(B_OBJS)
endif

$(NAME): $(OBJS)
		$(MAKE) -C ./utils
		cp utils/*.a $(NAME)
		ar -rcs $(NAME) $(OBJS)
		$(CC) $(CFLAGS) $(NAME) -o push_swap

all: $(NAME)

bonus:
		@make all WITH_BONUS=1

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

norm:
		@norminette -R CheckDefine $(INC)
		@norminette -R CheckForbiddenSourceHeader $(SRCS) $(B_SRCS) $(UTILS)

.PHONY: all clean fclean re bonus norm debug
