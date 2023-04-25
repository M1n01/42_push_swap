NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

INCDIR	=	./include
INC		=	$(INCDIR)/utils.h \
			$(INCDIR)/push_swap.h

SRCDIR	=	./srcs
SRCS	=	$(SRCDIR)/sort_long_middle.c \
			$(SRCDIR)/sort_long_utils.c \
			$(SRCDIR)/sort_long_bottom.c \
			$(SRCDIR)/sort_short.c \
			$(SRCDIR)/main.c \
			$(SRCDIR)/sort_short_utils.c \
			$(SRCDIR)/sort_long_top.c \
			$(SRCDIR)/sort_long.c
OBJS = $(SRCS:%.c=%.o)

UTILDIR	=	./utils
UTILS	=	$(UTILDIR)/find_list.c \
			$(UTILDIR)/make_stack_utils.c \
			$(UTILDIR)/make_stack.c \
			$(UTILDIR)/rules.c \
			$(UTILDIR)/command.c \
			$(UTILDIR)/stack_utils.c \
			$(UTILDIR)/error.c \
			$(UTILDIR)/rotate_utils.c \
			$(UTILDIR)/ans_utils.c \
			$(UTILDIR)/rules_utils.c \
			$(UTILDIR)/info_utils.c
UTILS_OBJ = $(UTILS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(UTILS_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(SRCS) $(UTILS) $(LIBFT) -o $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBDIR)

clean:
		$(MAKE) fclean -C $(LIBDIR)
		$(RM) $(OBJS) $(B_OBJS) $(UTILS_OBJ)

fclean: clean
		$(RM) $(NAME) $(LIB)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

.PHONY: all clean fclean re debug
