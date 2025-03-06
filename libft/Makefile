CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = 	src/ft_atoi.c src/ft_isalnum.c src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_strlen.c \
	src/ft_memset.c src/ft_bzero.c src/ft_memcpy.c src/ft_memmove.c src/ft_strlcpy.c \
	src/ft_strlcat.c src/ft_toupper.c src/ft_tolower.c src/ft_strchr.c src/ft_strrchr.c \
	src/ft_strncmp.c src/ft_memchr.c src/ft_memcmp.c src/ft_strnstr.c src/ft_calloc.c src/ft_strdup.c \
	src/ft_substr.c src/ft_strjoin.c src/ft_strtrim.c src/ft_split.c src/ft_itoa.c src/ft_putchar_fd.c  \
	src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_striteri.c src/ft_strmapi.c src/ft_printf.c \
	src/ft_print_format.c src/ft_putchar.c src/ft_putnbr_base.c src/ft_putnbr_u.c \
	src/ft_putnbr.c src/ft_putptr.c src/ft_putstr.c src/ft_putstr.c src/ft_strlen.c \
	src/get_next_line.c src/get_next_line_utils.c \

OBJDIR = obj
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

NAME = libft.a

GREEN = \033[0;32m
CLEAR = \033[0m

all: $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)✔ $(NAME) created and indxed$(CLEAR)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)✔ Libft Object files deleted$(CLEAR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)✔ $(NAME) deleted $(CLEAR)"

re: fclean all

.PHONY: all clean fclean re
