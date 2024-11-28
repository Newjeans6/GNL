NAME  = GNL.a
SRCS = get_next_line_utils.c get_next_line.c
ifdef BONUS
		SRCS:= $(SRCS) get_next_line_utils_bonus.c get_next_line_bonus.c
endif

OBJDIR = .obj
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
ar = ar rcs

$(OBJDIR)/%.o: %.c get_next_line.h
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus:
		$(MAKE) BONUS=1 all

$(NAME): $(OBJS)
		$(ar) $(NAME) $(OBJS)

clean:
		rm -rf $(OBJDIR)
fclean: clean
		rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re