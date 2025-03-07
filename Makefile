CC = cc
CFLAG = -Wall -Werror -Wextra

C_NAME = client
S_NAME = server

C_SRC = src/client.c \
		src/utils.c
S_SRC = src/server.c \
		src/utils.c

LIBFT = libft/libft.a
LIBFT_PATH = libft/

OBJDIR = obj
C_OBJ = $(C_SRC:%.c=$(OBJDIR)/%.o)
S_OBJ = $(S_SRC:%.c=$(OBJDIR)/%.o)

all: $(C_NAME) $(S_NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) -c $< -o $@

$(C_NAME) : $(C_OBJ) $(LIBFT)
	@$(CC) $(CFLAG) -o $@ $(C_OBJ) -L$(LIBFT_PATH) -lft
	@echo "$(GREEN)✔ Client created$(CLEAR)"

$(S_NAME): $(S_OBJ) $(LIBFT)
	@$(CC) $(CFLAG) -o $@ $(S_OBJ) -L$(LIBFT_PATH) -lft
	@echo "$(GREEN)✔ Server created$(CLEAR)"

%.o: %.c
	@$(CC) $(CFLAG) -c $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_PATH)

clean:
	@$(MAKE) -sC $(LIBFT_PATH) clean
	@rm -rf $(OBJDIR)
	@echo "$(CYAN)✔ Server and Client obj files deleted$(CLEAR)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_PATH) fclean
	@rm -f $(C_NAME) $(S_NAME)
	@echo "$(CYAN)✔ Server and Client deleted$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re 

GREEN = \033[0;32m
CYAN = \033[0;36m
CLEAR = \033[0m